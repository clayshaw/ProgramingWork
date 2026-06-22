import cv2
from time import sleep
from picamera2 import Picamera2
import time
import logging
from typing import Union
import os

log = logging.getLogger(__name__)
if not log.handlers:
    logging.basicConfig(level=logging.INFO)

class Camera:
    def __init__(self, camera: int = 0):
        self.picam2 = None
        self.frame = None
        for attempt in range(3):  # 最多嘗試 3 次
            try:
                self.picam2 = Picamera2(camera)
                config = self.picam2.create_video_configuration()
                self.picam2.configure(config)
                self.picam2.start()
                # short warm-up
                time.sleep(3)
                self.picam2.stop()
                print(f"✅ cam_{camera} 相機初始化完成") 
                break  # 成功初始化後跳出迴圈
            except Exception as e:
                print(f"❌ cam_{camera} 初始化失敗，嘗試次數 {attempt + 1}/3，真正的原因是: {e}") 
                os.system("sudo killall python3")  # 強制關閉所有 Python 程式，清理可能的資源占用
                time.sleep(2)  # 等待 2 秒後再試一次
                if attempt == 2:  # 最後一次嘗試失敗
                    print(f"❌ cam_{camera} 初始化失敗，已達最大嘗試次數，請檢查相機連接與驅動！")
                    exit(1)  # 結束程式
    

    def wake_up(self):
        """喚醒相機（PIR偵測到人時呼叫）"""
        # 🌟 補上防呆機制
        if self.picam2 is None:
            print("⚠️ 相機硬體未就緒，無法喚醒！")
            return
            
        try:
            self.picam2.start()
        except Exception as e:
            print(f"喚醒相機失敗: {e}")

    def read(self):
        """單純擷取畫面，不再包含 start()"""
        # 🌟 防呆：如果初始化失敗，直接回傳 None
        if self.picam2 is None:
            time.sleep(1) # 避免狂洗畫面
            return None
            
        try:
            # 1. 抓取原始陣列
            frame = self.picam2.capture_array()
            
            # 2. 調整大小
            frame = cv2.resize(frame, (640, 480))
            
            # 3. 🎨 解決色澤異常：將 RGB 轉換為 OpenCV 專用的 BGR
            # (取代掉你原本的 cv2.COLOR_BGRA2RGB)
            frame = cv2.cvtColor(frame, cv2.COLOR_RGB2BGR)
            
            # 4. 🔄 解決 180 度翻轉：使用 cv2.flip
            # 第一個參數是畫面，第二個參數 -1 代表「同時進行水平與垂直翻轉」(也就是轉 180 度)
            # frame = cv2.flip(frame, -1)
            
            self.frame = frame
            return frame
            
        except Exception as e:
            print(f"讀取畫面時發生錯誤: {e}")
            return None

    def sleep_down(self):
        # 🌟 加入防呆
        if self.picam2 is None: return
        try:
            self.picam2.stop()
        except Exception as e:
            print(f"關閉相機失敗: {e}")
    def mstop(self):
        try:
            self.picam2.stop()
        except Exception:
            log.exception("相機STOP失敗")
            
    def __del__(self):
        try:
            if self.picam2 is not None:
                self.picam2.stop()
                del self.picam2
                import gc
                gc.collect()
                log.info("相機資源已釋放")
        except Exception:
            log.exception("相機釋放失敗")

def main():
    cam = Camera()
    if cam.picam2 is None:
        print("無法初始化相機")
        return
    while True:
        frame = cam.read()
        cv2.imshow("Camera", frame)
        cv2.waitKey(1) 

if __name__ == "__main__":
    main()