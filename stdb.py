import tkinter as tk
import csv

def stid():
    with open('stdb.csv','r',newline='') as file:
        reader = csv.reader(file)
        i=0
        for row in reader:
            i=i+1
    i=i+1001
    return i

        

def writedb(fn,ln,rn,pn):
    with open('stdb.csv','a+',newline='') as file:
        writer = csv.writer(file)
        writer.writerow([fn,ln,rn,pn,stid()])
        

def buttonPress():
    first=fname.get() 
    last=lname.get()
    roll=rname.get()
    phone=pname.get()
    writedb(first,last,roll,phone)

trial=['Aryan','Thakur',56,9876543] #trial to check display box (text)

master=tk.Tk()
master.geometry('500x200')
master.title('Student Database v1.0')
lb=tk.Label(master,text='Welcome to the Student Portal')
lb.pack()
cv=tk.Canvas(master)
fname=tk.Entry(cv,text='First name')
flabel=tk.Label(cv,text='First name')
lname=tk.Entry(cv,text='Last name')
llabel=tk.Label(cv,text='Last name')
rname=tk.Entry(cv,text='Roll number')
rlabel=tk.Label(cv,text='Roll number')
pname=tk.Entry(cv,text='Phone number')
plabel=tk.Label(cv,text='Phone number')
plabel.grid(column=2,row=1)
pname.grid(column=3,row=1)
rlabel.grid(column=0,row=1)
rname.grid(column=1,row=1)
llabel.grid(column=2,row=0)
lname.grid(column=3,row=0)
flabel.grid(column=0,row=0)
fname.grid(column=1,row=0)
cv.pack()
but=tk.Button(master,text='Done',command=buttonPress)
but.pack()
txet=tk.Text(master)
txet.insert('1.0',trial)
txet.pack()
master.mainloop()

