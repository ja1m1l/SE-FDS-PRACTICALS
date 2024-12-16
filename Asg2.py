'''Write a Python program to store marks scored in subject “Fundamental of Data
Structure” by N students in the class. Write functions to compute following:
a) The average score of class
b) Highest score and lowest score of class
c) Count of students who were absent for the test
d) Display mark with highest frequency'''

# NAME - JAIMIL S PATEL
# ROLL NO - 15

FDS=[]
P=[]
AB=[]
student=int(input("Enter No Of Students :"))

for i in range(student):
   s=input("Enter Marks Of Students :")
   FDS.append(s)
   
for i in FDS:
     if i == 'AB':
            AB.append(1)
     else:
            P.append(int(i))
            
def maxmarks(P):
    LN=P[0]
    for j in P:
        if LN < j:
           LN = j
    return LN
    
def minmarks(P):
    SN=P[0]
    for k in P:
        if SN > k:
           SN = k
    return SN
     
def avg(P):
       add=0
       for var in P:
               add=add+var
       return add/len(P)
       
def freqq(FDS):
    max = 0
    rs = FDS[0]
    for i in FDS:
        freq = FDS.count(i)
        if freq > max:
           max = freq
           rs = i
    return rs

while True:
        choice =int(input("Enter Your Choice :"))
        if choice == 1:
               print(avg(P))
        if choice == 2:
               print("The Highest Marks Are : ",maxmarks(P))
               print("The Lowest Marks Are : " ,minmarks(P))
        if choice == 3:
               print("The Number Of Absent Students Are : ",len(AB))
        if choice == 4:
               print("The Frequency Is :", freqq(FDS))
        if choice == 5:
               print("Enter A Valid Choice")
               break;    
            
          
        
