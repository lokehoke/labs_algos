a = [2, 1, 4, 1, 2, 3, 1, 2, 4, 2, 3, 1]

a.sort()
a.reverse()

wrappers = []

for i in a:
    for j in wrappers:
        if sum(j) + i <= 6:
            j.append(i)
            break
    else:
        wrappers.append([i])


for i in wrappers:
    print(i)
