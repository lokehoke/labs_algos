import matplotlib.pyplot as plt


class Point:
    def __init__(self, x, y, name):
        self.x = x
        self.y = y
        self.name = name
        self.type = 'point'

    def plot(self):
        pass


class Line:
    def __init__(self, p1, p2):
        self.p1 = p1
        self.p2 = p2
        self.name = p1.name + p2.name
        self.type = 'line'

    def plot(self):
        plt.plot([self.p1.x, self.p2.x], [
                 self.p1.y, self.p2.y], label=self.name)


class Plex:
    def __init__(self, p1, p2, parent=None):
        self.parent = parent
        self.line = Line(p1, p2)
        self.children = [p1, p2]
        self.type = 'plex'

    def print_points(self):
        for i in self.children:
            if i.type in ('point'):
                print(i.name)
            elif i.type in ('plex'):
                i.print_points()

    def print_lines(self):
        print(self.line.name)
        for i in self.children:
            if i.type in ('plex'):
                i.print_lines()

    def add_line(self, p1, p2):
        for i in (0, 1):
            if self.children[i].type in ('point') and self.children[i].name == p1.name:
                self.children[i] = Plex(self.children[i], p2, self)
                return True
            elif self.children[i].type in ('plex') and self.children[i].add_line(p1, p2):
                return True
        return False

    def plot(self):
        self.line.plot()
        for i in self.children:
            i.plot()


if __name__ == '__main__':
    p1 = Point(0, 0, 'A')
    p2 = Point(10, 10, 'B')
    root = Plex(p1, p2)

    while True:
        code = int(
            input("What should be done:\n1 - print points\n2 - add line\n3 - plot\n4 - print lines\n0 - exit\nyour input: "))
        if code == 1:
            print('Points: ')
            root.print_points()
            print('End of points.')
        elif code == 2:
            print('Points: ')
            root.print_points()
            print('End of points.')
            name = input('Choice point: ')
            p1 = Point(0, 0, name)
            name = input('Enter name of new point: ')
            [x, y] = map(int, input('Enter x y: ').split(' '))
            root.add_line(p1, Point(x, y, name))
        elif code == 3:
            root.plot()
            plt.legend()
            plt.grid()
            plt.show()
        elif code == 4:
            print('Lines: ')
            root.print_lines()
            print('End of lines.')
        elif code == 0:
            print('goodbye')
            break
        else:
            continue
