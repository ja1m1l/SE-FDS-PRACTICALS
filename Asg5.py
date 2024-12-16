def phonebook(phbk):
    print("Phone Book Records")
    for record in phbk:
        print(record)

def binary_search_nonrec(arr, low, high, x):
    while low <= high:
        mid = (low + high) // 2
        if arr[mid][0] < x:
            low = mid + 1
        elif arr[mid][0] > x:
            high = mid - 1
        else:
            return mid
    return -1

def binary_search_rec(arr, low, high, x):
    
    if low > high:
        return -1
    mid = (low + high) // 2
    if arr[mid][0] == x:
        return mid
    elif arr[mid][0] > x:
        return binary_search_rec(arr, low, mid - 1, x)
    else:
        return binary_search_rec(arr, mid + 1, high, x)

def insert(phbk,name):
    mob=int(input("Enter Mobile Number: "))
    phbk.append([name,mob])
    phbk.sort()
    print("Updated Phonebook Is:")
    print(phbk)

phbk = [['jaimil', 123], ['bhavesh', 456], ['sahil', 789]]
phbk.sort()

print("Phone Book Records")
phonebook(phbk)

print("\nMenu")
print("1. Search Record")
print("2. Insert")
print("3. Exit")

while True:
    choice = input("Enter Your Choice: ")
    
    if choice == "1":
        x = input("Enter Friend You Want To Search: ")
        method = input("Choose search method (nonrec/rec): ")
        
        if method == "nonrec":
            result = binary_search_nonrec(phbk, 0, len(phbk) - 1, x)
        elif method == "rec":
            result = binary_search_rec(phbk, 0, len(phbk) - 1, x)
        else:
            print("Invalid search method! Please enter 'nonrec' or 'rec'.")
            continue
        
        if result != -1:
            print(f"{x} is present at index {result} in phonebook.")
        else:
            print(f"{x} is not present in phonebook.")
    
    elif choice == "2":
        x1 = input("Enter Name to Insert: ")
        if binary_search_nonrec(phbk, 0, len(phbk) - 1, x1) == -1:
            print(f"{x1} is not present in phonebook.")
            print(f"Friend {x1} is now inserted in phonebook.")
            insert(phbk, x1)
        else:
            print(f"{x1} is already present in the phonebook.")

    elif choice == "3":
        print("Exiting the program. Goodbye!")
        break
    
    else:
        print("Invalid choice. Please enter a valid option.")