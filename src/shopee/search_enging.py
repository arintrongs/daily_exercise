t = int(input())
tq = 1
while tq <= t:
    n, q = input().split(' ')
    n = int(n)
    q = int(q)
    d = {}

    for i in range(n):
        s = input().split(' ')
        cd = set()
        for j in range(len(s)):
            for k in range(j+1, len(s)+1):
                st = ' '.join(s[j:k])
                if(st not in d):
                    d[st] = 0
                if(st not in cd):
                    cd.add(st)
                    d[st] += 1
    print('Case '+str(tq)+': ')
    for i in range(q):
        query = input()
        if(query in d):
            print(d[query])
        else:
            print(0)
    tq += 1
