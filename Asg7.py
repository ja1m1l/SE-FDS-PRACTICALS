def longestword(s):
    words=s.split()
    longest=max(words,key=len)
    return longest

def charfrequency(s,char):
    return s.count(char)

def ispaliindrome(s):
    return s==s[::-1]

def firstsubstringindex(s,sub):
    return s.find(sub)

def wordoccurences(s):
    words=s.split()
    wordcount={}
    for word in words:
        wordcount[word]=wordcount.get(word,0)+1
    return wordcount

s="Hello World"
char='e'
sub='Hello'
print("The Longest Word Is: ",longestword(s))
print("Frequency Of Character Is '{}' :".format(char),charfrequency(s,char))
print("Is It Palindrome? ",ispaliindrome(s))
print("Word Occurences: ",wordoccurences(s))
print("First Substring Index '{}' :".format(sub),firstsubstringindex(s,char))