#!/usr/bin/env python
import re
import collections
#from collections import Counter

def word_count(myBookPath, count):
    with open(myBookPath) as f:
        passage = f.read()
        words = re.findall(r'\w+', passage)
        cap_words = [word.upper() for word in words]
    word_counts = collections.Counter(cap_words)
    print cap_words


def word_count_v2(myBookPath, count):
    with open(myBookPath) as f:
        text = f.read.lower()
    words = re.findall(r'\w+', text)
    print(Counter(words).most_common(count))

def main():
    word_count("books.txt", 5)
    word_count_v2("books.txt", 5)

main()



#!/usr/bin/env python
def word_occurences(Myfile, count):
    word_with_count = {}
    with open(Myfile) as f:
        for line in f.readlines():
            for word in line.split():
                if word in word_with_count:
                    #import pdb;pdb.set_trace()
                    word_with_count[word] += 1
                else:
                    word_with_count[word] = 0

    words = []
    #for key, value in word_with_count.iteritems():
    print word_with_count
    for key, value in word_with_count.iteritems():
        if value == count:
            words.append(key)

    return words

if __name__ == "__main__":
    RetWords = word_occurences("books.txt", 4)
    print RetWords



#!/usr/bin/env python
def pairSum(arr, k):
    if len(arr) < 2:
        return
    arr.sort()
    left,right = (0, len(arr)-1)
    while left < right:
        currSum = arr[left] + arr[right]
        if currSum == k:
            print arr[left], arr[right]
            left+=1
        elif currSum < k:
            left+=1
            #right-=1
        else:
            right-=1

def pairSum2(arr,k):
   result = False
   for i in arr:
       look = k - i
       if look > 0 and look in arr:
           result = True
           print str(i)+' + '+str(look)

   if not result:
       print 'No combnation found'


def main():
    A = [5,0,-8, 10, 3, -13, 6,8,4]
    #A = [-13, 4, 2]
    x = 9
    pairSum(A, x)
    #print('%d %d' % (A[0], A[1]))
    #print('%d' % (A[0]+A[1]))
    #Comp = 9
    #if A[0]+A[1] < Comp:
    #    print "Yes"
main()


class Node(object):
  def __init__(self, value, left=None, right=None):
    self.value = value
    self.left = left
    self.right = right

def traverse(rootnode):
  thislevel = [rootnode]
  while thislevel:
    nextlevel = list()
    for n in thislevel:
      print n.value,
      if n.left: nextlevel.append(n.left)
      if n.right: nextlevel.append(n.right)
    print
    thislevel = nextlevel

t = Node(1, Node(2, Node(4, Node(7))), Node(3, Node(5), Node(6)))

traverse(t)
