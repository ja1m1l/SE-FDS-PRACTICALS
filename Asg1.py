'''In second year computer engineering class, group A students play cricket, group B
students play badminton and group C students play football.
Write a Python program using functions to compute following: -
a) List of students who play both cricket and badminton
b) List of students who play either cricket or badminton but not both
c) Number of students who play neither cricket nor badminton
d) Number of students who play cricket and football but not badminton.'''

# NAME - JAIMIL S PATEL
# ROLL NO - 15

lst1=['BHAVESH','JAIMIL','SAHIL'] #cricket
lst2=['ADITYA','YASH','SAHIL'] #badminton
lst3=['JAIMIL','BHAVESH','ADITYA'] #football

def intersection(lst1,lst2):
    lst4=[]
    for val in lst1:
        if val in lst2:
            lst4.append(val)
    return lst4
    
def union(lst1,lst2):
    lst4=lst1.copy()
    for val in lst2:
        if val not in lst4:
           lst4.append(val)
    return lst4

def diff(lst1,lst2):
    lst4=[]
    for val in lst1:
        if val not in lst2:
            lst4.append(val)
    return lst4
    
def sym_diff(lst1,lst2):
    lst4=[]
    s1=diff(lst1,lst2)
    s2=diff(lst2,lst1)
    lst4=union(s1,s2)
    return lst4

lst4=intersection(lst1,lst2)
print("students who play both badminton and cricket",lst4)
    
lst4=sym_diff(lst1,lst2)
print("student who play either cricket or badminton but not both",lst4)

lst4=diff(lst3,union(lst1,lst2))
print("no.of student play niether cricket not badminton =",len(lst4))

lst4=diff(intersection(lst1,lst3),lst2)
print("no of student who play cricket and football but not badminton",len(lst4))
