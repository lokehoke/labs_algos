def bin_search(arr, el):
    l, r = 0, len(arr) - 1
    while r - l >= 0:
        i = (l + r) // 2
        if arr[i] == el:
            return i
        elif arr[i] < el:
            l = i + 1
        else:
            r = i - 1
    return None

def main():
    array = [3, 4, 6, 8, 13, 16, 19, 27, 27, 34, 39, 41, 41, 52, 78]
    print(bin_search(array, 3))
    print(bin_search(array, 27))
    print(bin_search(array, 26))
    print(bin_search(array, 78))

if __name__ == '__main__':
    main()
