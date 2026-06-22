import time
import threading
from gpiozero import AngularServo, MotionSensor, TonalBuzzer,DistanceSensor
from gpiozero.tones import Tone
from mfrc522 import SimpleMFRC522
import cv2

from camera import Camera
from detect import detector

# ==================== 硬體初始化 ====================
print("系統初始化中...")
# 1. 伺服馬達 (SG90) - 接 GPIO 14
servo = AngularServo(
    pin=14, 
    initial_angle=90, 
    min_pulse_width=0.0005,
    max_pulse_width=0.0025
)
sensor = DistanceSensor(echo=24, trigger=23, max_distance=2.0)

# 2. 紅外線人體感測器 (E104) - 接 GPIO 4
pir = MotionSensor(4)

# 3. 無源蜂鳴器 - 接 GPIO 22
buzzer = TonalBuzzer(22)

# 4. RFID 讀卡機 (RC522)
reader = SimpleMFRC522()

# 5. AI 模組
my_detector = detector()
my_camera = Camera()

time.sleep(0.5)
servo.detach()

# ⚠️ 請把剛剛測出來的卡號填入這裡！
ALLOWED_RFID_UIDS = [907699730221]

lock_mutex = threading.Lock()
print("系統初始化完成，開始待命！")

# ==================== 音效控制函數 ====================
def play_success_sound():
    """成功音效：短促的升調 (Do-Mi-Sol)"""
    try:
        buzzer.play(Tone("C5"))
        time.sleep(0.1)
        buzzer.play(Tone("E5"))
        time.sleep(0.1)
        buzzer.play(Tone("G5"))
        time.sleep(0.15)
        buzzer.stop()
    except Exception:
        pass

def play_fail_sound():
    """失敗音效：低沉的兩聲警報 (叭-叭-)"""
    try:
        buzzer.play(Tone("A3"))
        time.sleep(0.2)
        buzzer.stop()
        time.sleep(0.1)
        buzzer.play(Tone("A3"))
        time.sleep(0.3)
        buzzer.stop()
    except Exception:
        pass

# ==================== 共用開門邏輯 ====================
def open_door(method_name):
    """控制馬達開門，播放音效，幾秒後自動上鎖"""
    with lock_mutex:
        print(f"✅ [{method_name}] 驗證成功，開門！")
        play_success_sound() # 播放開門音效
        
        servo.angle = 0  # 轉到 0 度開門
        time.sleep(0.5)  # 等待馬達轉動到位
        servo.detach()  # 解除控制，讓馬達自由旋轉
        time.sleep(5)    # 保持開門狀態 5 秒
        servo.angle = 90 # 轉回 90 度上鎖
        time.sleep(0.5)  # 等待馬達轉動到位
        servo.detach()  # 解除控制，讓馬達自由旋轉
        print("🔒 門已自動上鎖。")

def reject_access(method_name, reason):
    """拒絕開門邏輯"""
    print(f"❌ [{method_name}] 驗證失敗：{reason}")
    play_fail_sound()

# ==================== 執行緒 1：RFID 獨立監聽 ====================
def rfid_loop():
    print("[RFID] 讀卡機待命中...")
    while True:
        try:
            uid, text = reader.read()
            print(f"[RFID] 掃描到卡片，UID: {uid}")
            
            if uid in ALLOWED_RFID_UIDS:
                open_door("RFID 卡片")
            else:
                reject_access("RFID", "未經授權的卡片")
                
            time.sleep(2) # 避免連續狂嗶
        except Exception as e:
            continue

# ==================== 執行緒 2：PIR 與 人臉辨識 ====================
def face_detection_loop():
    camera_is_on = False
    
    while True:
        if pir.is_active or (sensor.distance < 0.5):  
            print( "PIR偵測到活動" if pir.is_active else "距離感測器偵測到近距離物體")
            if not camera_is_on:
                my_camera.wake_up()
                camera_is_on = True
                time.sleep(0.5) 
                
            frame = my_camera.read()
            if frame is not None:
                my_detector.detect(frame)
                
                if my_detector.iscorrect:
                    open_door("人臉辨識")
                    time.sleep(3)
                elif my_detector.frame is not None and not my_detector.iscorrect:
                    best_name = getattr(my_detector, 'best_name', 'Unknown')
                    
                    if best_name == "Unknown":
                        reject_access("人臉辨識", "陌生人臉")
                        time.sleep(3) 
                    
        else:
            if camera_is_on:
                print("💤 周遭無人，關閉相機進入省電模式...")
                my_camera.sleep_down()
                camera_is_on = False
                my_detector.iscorrect = False 
                
        # 🌟 關鍵修復：不管有沒有偵測到人，迴圈跑完一次都休息 0.1 秒，防止 CPU 100% 暴衝與 GPIO 崩潰
        time.sleep(0.1)
                

# ==================== 主程式啟動 ====================
if __name__ == "__main__":
    try:
        rfid_thread = threading.Thread(target=rfid_loop, daemon=True)
        rfid_thread.start()

        face_thread = threading.Thread(target=face_detection_loop, daemon=True)
        face_thread.start()

        # 🛑 刪除 show_thread，把 imshow 移到主迴圈！

        while True:
            # 在主執行緒更新畫面
            if my_camera.frame is not None:
                cv2.imshow("Camera", my_camera.frame)
            
            # 🌟 整個程式只能有「一個」 cv2.waitKey，且必須在主執行緒
            if cv2.waitKey(1) & 0xFF == ord('q'):
                print("按下 Q 鍵，手動退出程式...")
                break

    except KeyboardInterrupt:
        print("\n收到中斷指令，準備安全關閉系統...")
    finally:
        buzzer.stop() 
        my_camera.__del__()
        servo.detach()
        cv2.destroyAllWindows() # 關閉所有 OpenCV 視窗
        print("系統已關閉。")