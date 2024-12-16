'''Write a Python program that computes the net amount of a bank account based a
transaction log from console input. The transaction log format is shown as following: D
100 W 200 (Withdrawal is not allowed if balance is going negative. Write functions for
withdraw and deposit) D means deposit while W means withdrawal.
Suppose the following input is supplied to the program:
D 300, D 300 , W 200, D 100 Then, the output should be: 500'''

# NAME - JAIMIL S PATEL
# ROLL NO - 15


tlog = []
balance=0

while True:

      data = input("Please Enter Transaction Details As D amt / W amt & Enter 'Exit' To EXIT")
      if data == 'Exit':
         break
         
      tlog.append(data.split())
      
print(tlog)

def deposit(amt):
    global balance
    balance = balance + amt
    
def withdraw(amt):
    global balance
    balance = balance - amt

for var in tlog:
    if var[0] == 'D':
       deposit(int(var[1]))
       
    elif var[1] == 'W':
       withdraw(int(var[1]))

if balance<0:
   print("Insufficient Funds :")

else:
   print("Balance Is : ", balance)


    
    
