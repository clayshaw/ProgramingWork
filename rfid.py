from mfrc522 import SimpleMFRC522
import time

reader = SimpleMFRC522()

print("==== RFID UID 讀取程式 ====")
print("請將你要註冊的卡片或磁扣靠近讀卡機...")

try:
    # 程式會停在這裡等，直到感應到卡片
    uid, text = reader.read()
    print("\n✅ 讀取成功！")
    print(f"請將這串數字複製下來： {uid}")
    print("===========================")
    
except Exception as e:
    print(f"讀取錯誤: {e}")
finally:
    # 避免資源佔用
    print("程式結束。")