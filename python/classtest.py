


class MyClass:
    '''This is my first class'''

    i = 123

    def __init__(self, h):
        self.h = h

    def my_func():
        print("call my func")


print(MyClass.__doc__)
print(MyClass.i)
b = MyClass(8)
print(b.i)
MyClass.i = 9;
print(MyClass.i)

c= MyClass(5)
print(c.i)
print(b.i)

c.i=15

print(c.i)
print(b.i)
print(MyClass.i)
