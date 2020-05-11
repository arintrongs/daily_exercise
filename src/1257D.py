t = int(input())
anss = []
for q in range(t):
    m = int(input())
    monsters = input().split(' ')
    monsters = [int(x) for x in monsters]
    n = int(input())
    heroes = []
    for i in range(n):
        atk, endurance = input().split(' ')
        atk = int(atk)
        endurance = int(endurance)
        heroes.append([atk, endurance])
    mx = len(heroes) * [0]
    heroes.sort(key=lambda x: (x[0], x[1]))
    mxx = 0
    for i in range(len(heroes) - 1, -1, -1):
        mxx = max(mxx, heroes[i][1])
        mx[i] = mxx

    start = 0
    end = 0
    mx_mon = 0
    ans = 0
    possible = True
    mx_mon2 = max(monsters)
    mx_hero2 = max([x[0] for x in heroes])
    if(mx_mon2 > mx_hero2):
        possible = False

    if(possible):
        while(end < len(monsters)):
            mx_mon = max(mx_mon, monsters[end])
            # print('mx_mon : ', mx_mon, monsters[end])
            endurance = end-start + 1
            l = 0
            r = len(heroes) - 1
            print('start end : ', start, end)
            while(l <= r):
                m = (l+r) // 2
                # print(l, r, m, heroes[m], mx_mon)
                if(heroes[m][0] >= mx_mon):
                    r = m - 1
                elif(heroes[m][0] < mx_mon):
                    l = m + 1
                else:
                    break

            # print('find : ', mx_mon, heroes[l],
            #       mx[l], endurance, end, len(monsters), ans)

            if(heroes[l][0] >= mx_mon and mx[l] >= endurance):
                end += 1
                if(end == len(monsters)):
                    ans += 1
            else:
                start = end
                ans += 1
                mx_mon = monsters[start]
    if(possible):
        anss += [ans]
    else:
        anss += [-1]

print("\n".join([str(x) for x in (anss)]))
