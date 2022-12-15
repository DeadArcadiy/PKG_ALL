import numpy as np
import cv2 as cv
from tkinter import ttk
from tkinter import *
from PIL import ImageTk
import PIL
from matplotlib import pyplot as plt
import os

class MainSolution():
    def __init__(self):
      self.image = cv.imread('lin.jpg',cv.IMREAD_GRAYSCALE)
      self.imgray = cv.imread('high.jpg',cv.IMREAD_GRAYSCALE)
      self.lowcontrast = cv.imread('lin.jpg',cv.IMREAD_GRAYSCALE)

    def log(self):
      kernel = np.array([[0,0,-1,0,0], [0,-1,-2,-1,0], [-1,-2,16,-2,-1],[0,-1,-2,-1,0],[0,0,-1,0,0]])
      log = cv.filter2D(self.imgray, -1, kernel)
      log = PIL.Image.fromarray(log)
      img = log.resize((300, 300))
      return ImageTk.PhotoImage(img)

    def laplasian(self):
      kernel = np.array([[-1,-1,-1], [-1,9,-1],[-1,-1,-1]])
      laplasian = cv.filter2D(self.imgray, -1, kernel)
      laplasian = PIL.Image.fromarray(laplasian)
      img = laplasian.resize((300, 300))
      return ImageTk.PhotoImage(img)

    def histogram(self):
      imforh = self.image
      h = cv.calcHist([imforh], [0], None, [256], [0,256])
      plt.plot(h,color = 'red')
      plt.savefig('histogram.jpg')
      img = PIL.Image.fromarray(cv.imread('histogram.jpg'))
      img= img.resize((300,300))
      #########  
      dst = cv.equalizeHist(imforh)
      h = cv.calcHist([dst], [0], None, [256], [0,256])
      dst = PIL.Image.fromarray(dst)
      dst = dst.resize((300,300))
      ##########     
      plt.clf()
      plt.plot(h,color = 'blue')
      plt.savefig('histogram2.jpg')
      img2 = PIL.Image.fromarray(cv.imread('histogram2.jpg'))
      img2 = img2.resize((300,300))
      os.remove('histogram2.jpg')
      os.remove('histogram.jpg')
      plt.close()
      return ImageTk.PhotoImage(img),ImageTk.PhotoImage(dst),ImageTk.PhotoImage(img2)

    def lincontast(self):
      minVal,maxVal,a,b = cv.minMaxLoc(self.lowcontrast)
      max_type = 255 
      a = max_type / (maxVal - minVal)
      image_of_doubles = a*(self.lowcontrast - minVal)
      image_of_doubles = PIL.Image.fromarray(image_of_doubles)
      img = image_of_doubles.resize((300, 300))
      return ImageTk.PhotoImage(img)

    def getorigs(self):
      img1 = PIL.Image.fromarray(self.imgray)
      img1 = img1.resize((300, 300))
      img2 = PIL.Image.fromarray(self.lowcontrast)
      img2 = img2.resize((300, 300))
      img3 = PIL.Image.fromarray(self.image)
      img3 = img3.resize((300, 300))
      return ImageTk.PhotoImage(img1),ImageTk.PhotoImage(img2),ImageTk.PhotoImage(img3)

if __name__ == "__main__":
    root = Tk()
    ms = MainSolution()
    img3,img5,img4 = ms.histogram()
    w, h = root.winfo_screenwidth(), root.winfo_screenheight()
    root.geometry(f"1100x1100")
    lbl_text1 = ttk.Label(text="Высокочастотные фильтры")
    lbl_text1.place(x=500, y=10)
    img1 = ms.log()
    lbl1 = ttk.Label(image=img1)
    lbl1.image = img1
    lbl1.place(x=710, y=40, width=300, height=300)
    img2 = ms.laplasian()
    lbl2 = ttk.Label(image=img2)
    lbl2.image = img2
    lbl2.place(x=370, y=40, width=300, height=300)
    lbl_text2 = ttk.Label(text="Построение и эквализация гистограммы")
    lbl_text2.place(x=300, y=700)
    lbl3 = ttk.Label(image=img3)
    lbl3.image = img3
    lbl3.place(x=30, y=390, width=300, height=300)
    lbl_text3 = ttk.Label(text="Линейное контрастирование")
    lbl_text3.place(x=800, y=700)
    img6 = ms.lincontast()
    lbl4 = ttk.Label(image=img4)
    lbl4.image = img4
    lbl4.place(x=10, y=740, width=300, height=300)
    lbl5 = ttk.Label(image=img5)
    lbl5.image = img5
    lbl5.place(x=370, y=740, width=300, height=300)
    lbl6 = ttk.Label(image=img6)
    lbl6.image = img6
    lbl6.place(x=710, y=740, width=300, height=300)
    orig1,orig2,orig3 = ms.getorigs()
    lbl7 = ttk.Label(image=orig1)
    lbl7.image = orig1
    lbl7.place(x=30, y=40, width=300, height=300)
    lbl8 = ttk.Label(image=orig2)
    lbl8.image = orig2
    lbl8.place(x=710, y=390, width=300, height=300)
    lbl9 = ttk.Label(image=orig3)
    lbl9.image = img3
    lbl9.place(x=370, y=390, width=300, height=300)
    root.mainloop()
    plt.close()