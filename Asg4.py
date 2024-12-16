#write a python program to store first year percentage of student in array. write function of sorting array of floating point numbers in
#ascending order using 1)selection sort 2)bubble sort & display top 5 scores.
#NAME - JAIMIL PATEL
#SE B 15
def selectionsort(arr):
    n = len(arr)

    for i in range(n):
        ss = i

        for j in range(i+1, n):

            if arr[j] < arr[ss]:
               ss = j  

        arr[i], arr[ss] = arr[ss], arr[i]

    return arr
    
def bubblesort(arr):
    n = len(arr)

    for i in range(n):

        for j in range(0, n-i-1):

            if arr[j] > arr[j+1]:
               arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr
    
def dtf(arr):
    print("Top five scores:")

    for i in range(len(arr)-1, len(arr)-6, -1):

        print(arr[i])

p=[]
data=int(input("Enter Number Of Students: "))
for k in range(data):
       percentages=float(input("Enter Percentages Of Students: "))
       p.append(percentages)
       
print("1.Selection Sort")  
print("2.Bubble Sort")
print("3.Top 5 Scores")  
print("4.Exit")  
print("Original array:")
print(p)

while True:
   choice=int(input("Enter Your Choices: "))
   if choice==1:

      sps= selectionsort(p.copy())
      print("\nSorted array using Selection Sort:")
      print(sps)

   elif choice==2:

      spb = bubblesort(p.copy())
      print("\nSorted array using Bubble Sort:")
      print(spb)
      
   elif choice==3:
      dtf(sps)
   
   elif choice==4:
      break
   
   else:
      print("Enter A Valid Choice")
