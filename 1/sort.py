from random import seed
from random import random
from datetime import datetime


def merge(l, r):
    res = []
    i, j = 0, 0
    while i < len(l) and j < len(r):
        if l[i] < r[j]:
            res.append(l[i])
            i += 1
        else:
            res.append(r[j])
            j += 1
    while i < len(l):
        res.append(l[i])
        i += 1
    while j < len(r):
        res.append(r[j])
        j += 1
    return res


def merge_sort(arr):
    if len(arr) < 2:
        return arr[:]
    else:
        m = int(len(arr) / 2)
        l = merge_sort(arr[:m])
        r = merge_sort(arr[m:])
        return merge(l, r)


def insertion(arr):
    for i in range(len(arr)):
       j = i
       while j > 0 and arr[j] < arr[j -1]:
            arr[j], arr[j-1] = arr[j-1], arr[j]
            j -= 1
    return arr


def main():
    array = [78, 41, 4, 27, 3, 27, 8, 39, 19, 34, 6, 41, 13, 52, 16]
    print(merge_sort(array))
    print(insertion(array))

    seed(1)
    for n in (1000, 4000, 6000):
        arr = []
        for i in range(n):
            arr.append(random())
            i += 1
        st = datetime.now()
        merge_sort(arr)
        print(f"merge_sort ({n}):{(datetime.now() - st).microseconds}")

    for n in (1700, 2800, 7500):
        arr = []
        for i in range(n):
            arr.append(random())
            i += 1
        st = datetime.now()
        insertion(arr)
        print(f"insertion ({n}):{(datetime.now() - st).microseconds}")


if __name__ == '__main__':
    main()

