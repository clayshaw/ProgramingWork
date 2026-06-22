import tkinter as tk
from time import sleep
from PIL import Image, ImageTk
import cv2
import threading
from camera import Camera
from detect import detector
import time


window = tk.Tk()
window.title("face Detection")
window.geometry("700x600")
window.resizable(False, False)
my_detector = detector()
my_camera = Camera()
if my_camera.picam2 is None:
    print("無法初始化相機")
    exit()

video_label = tk.Label(window, text="Video Stream")
video_label.pack(pady=20)

input_frame = tk.Frame(window)
input_frame.pack(pady=10)

text_input = tk.Entry(input_frame)
text_input.pack(side=tk.LEFT, padx=5)

btn = tk.Button(input_frame, text="take photo", command=lambda: my_detector.sing_up(text_input.get(), my_camera.frame))
btn.pack(side=tk.LEFT, padx=5)






def update_gui():
    if my_detector.frame is not None:
        try:
            img = my_detector.frame.copy()
            img = Image.fromarray(img)
            imgtk = ImageTk.PhotoImage(image=img)
            
            video_label.imgtk = imgtk 
            video_label.configure(image=imgtk)
        except Exception as e:
            print(f"更新畫面錯誤: {e}")
    elif my_camera.frame is not None:
        img = my_camera.frame.copy()
        img = Image.fromarray(img)
        imgtk = ImageTk.PhotoImage(image=img)
        
        video_label.imgtk = imgtk 
        video_label.configure(image=imgtk)
    window.after(30, update_gui)  

def detect_loop():
    while True:
        my_detector.detect(my_camera.frame)
def camera_loop():
    while True:
        my_camera.read()
        time.sleep(0.01)


camera_thread = threading.Thread(target=camera_loop)
camera_thread.daemon = True
camera_thread.start()
detect_thread = threading.Thread(target=detect_loop)
detect_thread.daemon = True
detect_thread.start()

def destroy():
    my_camera.__del__()
    my_detector.__del__()
    window.destroy()

btn_close = tk.Button(input_frame, text="close", command=destroy)
btn_close.pack(side=tk.LEFT, padx=5)



update_gui()
window.mainloop()