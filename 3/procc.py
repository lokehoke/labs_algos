t = [4, 2, 5, 1, 6, 2, 7, 4, 5, 6, 1]
t.sort()
t.reverse()

proc = [None]*4
for i in range(4):
    proc[i] = []

for i in range(len(t)):
    min = proc[0]
    w = sum(proc[0])

    for j in proc:
        if sum(j) < w:
            w = sum(j)
            min = j

    min.append(t[i])

for i in proc:
    print(i)
