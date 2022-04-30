# -*- coding: utf-8 -*-
import random
import sys

s = ["H", "C", "R"]
file = open('1.in', 'w')
for i in range(500):
    l = []
    n = random.randint(2, 7)
    b_x = random.randint(1, 3)
    b_y = random.randint(4, 6)
    l.append((b_x, b_y))
    t_x = random.randint(8, 10)
    t_y = random.randint(4, 6)
    l.append((t_x, t_y))
    while (len(l) < 9):
        h_x = random.randint(1, 10)
        h_y = random.randint(1, 9)
        if((h_x, h_y) in l):
            continue
        l.append((h_x, h_y))
    x = []
    t = [0, 0, 0]
    x.append(0)
    x.append(1)
    file.write(str(n)+" "+str(b_x)+" "+str(b_y)+'\n')
    file.write("G "+str(t_x)+" "+str(t_y)+'\n')
    d = 1
    while(d < n):
        now = random.randint(0, 2)
        if(t[now] >= 2):
            continue
        now_2 = random.randint(2, 8)
        if(now_2 in x):
            continue
        x.append(now_2)
        t[now] += 1
        file.write(s[now] + " " + str(l[now_2][0]) + " " + str(l[now_2][1]))
        file.write('\n')
        d += 1
    file.write('\n')
file.write('0 0 0\n')
file.close()
