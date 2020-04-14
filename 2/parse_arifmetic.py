class stack:
    def __init__(self):
        self.__data = []

    def push(self, s):
        self.__data.append(s)
        return 0

    def pop(self):
        if len(self.__data) == 0:
            return 1
        else:
            self.__data.pop()
            return 0

    def size(self):
        return len(self.__data)


def main():
    print('Enter expression to parse:')
    a = input()
    while a != ' ':
        st = stack()
        error = 0
        for i in a:
            if i == '(':
                error = st.push(i)
            elif i == ')':
                error = st.pop()
            if error == 1:
                break

        if error == 0 and st.size() == 0:
            print('string is normal!')
        else:
            print('string with error!')

        print('Enter expression to parse')
        a = input()


if __name__ == '__main__':
    main()
