'''Write Python program to store 10th class percentage of students in array. Write function for sorting array of floating point numbers in 
ascending order using radix sort and display top five score'''

#NAME - JAIMIL PATEL
#ROLL NO - 15

def radixsort(arr,reverse=False):
    mx = max(arr)
    exp = 1

    while mx / exp >= 1:
        buckets = [[] for _ in range(10)]
        
        for num in arr:
            index = int(num * exp) % 10
            buckets[index].append(num)

        arr = [num for bucket in buckets for num in bucket]  
        exp *= 10

    if reverse:
        arr.reverse()
    return arr
    
percentages = [22.0, 31.1, 38.3, 45.4, 50.5, 80.7, 99.9]
print("Top 5 scores 10th std (ascending):", radixsort(percentages[:])[-5:])
print("Top 5 scores 10th std (descending):", radixsort(percentages[:], reverse=True)[:5])
