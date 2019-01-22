t=int(input())
for i in range(t):
    n=int(input())
    arr=[int(i) for i in input().split()]
    count=0
    arr1=list(set(arr))
    n1=len(arr1)
    for i in range(n1):
        for j in range(n1):
            if arr.count(arr1[i])>=arr1[j] and arr.count(arr1[j])>=arr1[i]:
    #            print(i,j)
                count=count+1

    print(count)            


"""
from sys import stdin
from collections import Counter

ans = []
for _ in range(int(input())):
    n = int(stdin.readline())
    ays = list(map(int, stdin.readline().split()))

    ca = sorted(Counter(ays).items())
    tot = 0
    for ix, pr in enumerate(ca):
        m,q = pr
        if q >= m:
            tot += 1
            for lm,lq in ca[ix+1:]:
                if q<lm:
                    break
                if lq>=m:
                    tot+= 2
    ans.append(tot)

print('\n'.join(map(str,ans)))
"""    