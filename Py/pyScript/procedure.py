print("hello python")
# input
# a = input("type something  :")
# print(a)

#list 
# weekdays = ['monday','tuesday','wednesday','thursday','friday','saturday','sunday']
# print(weekdays)
# print(len(weekdays))
# print(weekdays[0])
# print(weekdays[-1])
# print(weekdays[-2])
# weekdays.insert(1,'xxx')
# print(weekdays)
# weekdays.pop(1)
# print(weekdays)

#tuple 
# mytuple = (1,2)
# print(mytuple)
# print(mytuple.count)
# print(mytuple.index(2))
# oneTuple = (3,)
# print(oneTuple)


# conditional statement 
# a =111
# if a==10:
#     print('a==10')
# elif a==11:
#     print('a!=10')
# else:
#     print(a)


# loop
# sum = 0
# L=[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
# for x in L:
#     sum = sum + x
# print(sum)

# print(range(10))  #range(0, 10)
# print(list(range(10))) #[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

# for x in range(100):
#     print(x)
# a=10
# i=0;
# while i<a:
#     print("i=",i) 
#     i=i+1


# dict  (map) key-value 
# d = {'kangkang': 95, 'miachael': 75, 'maria': 85}
# print(d)
# print()
# print(d['kangkang'])

#set 
# s = set([1, 2, 3])
# print(s)
# s.add(3)
# print(s)
# s.add(55)
# print(s)

#function 
# def _max(a,b):
#     if a>b:
#         return a
#     else:
#         return b
# print(_max(10,14))

# age = 10
# if age >= 18:
#     pass 

# def returnTwo(a,b):
#     return a,b
# print(returnTwo(10,11))

# def returnList(a,b,c):
#     return [a,b,c]
# print(returnList(1,2,55))


# def f1(a, b, c=0, *args, **kw):
#     print('a =', a, 'b =', b, 'c =', c, 'args =', args, 'kw =', kw)

# def f2(a, b, c=0, *, d, **kw):
#     print('a =', a, 'b =', b, 'c =', c, 'd =', d, 'kw =', kw)

# f1(1, 2)
# f1(1, 2, c=3)
# f1(1, 2, 3, 'a', 'b')
# f1(1, 2, 3, 'a', 'b', x=99)
# f2(1, 2, d=99, ext=None)

#recursive function
# def f(n):
#     if n==1:
#         return 1
#     return n * f(n - 1)
# print(f(5))

#slice
# L = []
# n = 1
# while n <= 99:
#     L.append(n)
#     n = n + 2
# print(L)
# r=[]
# n=3
# for i in range(n):
#      r.append(L[i])
# print(r)
# print(L[0:3])
# print(L[-10:])
# print('/////////////////////////')
# newL = list(range(1000))
# print(newL[:20:2])
# print(newL[::5])

# print((0, 1, 2, 3, 4, 5)[:3])

#iteration 
# d = {'a': 1, 'b': 2, 'c': 3}
# for key in d:
#     print(key)
#     print(d[key])
# for value in d.values():
#     print(value)

#list comprehensions

# # list [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
# print(list(range(1,11))) #[)

# #[1x1, 2x2, 3x3, ..., 10x10]
# L = []
# for x in range(1, 11):
#     L.append(x * x)
# print(L)
# print([x * x for x in range(1, 11)])

# generator
# g = (x * x for x in range(10))
# print(next(g))
# print(next(g))
# print(next(g))
# print(next(g))
# print(next(g))
# print(next(g))
# print(next(g))
# print(next(g))
# print(next(g))
# print(next(g))

# newg = (x*x for x in range(100))
# for i in newg:
#     print(i)


# def odd():
#     print('step 1')
#     yield 1
#     print('step 2')
#     yield(3)
#     print('step 3')
#     yield(5)
# o=odd()
# next(o)
# next(o)
# next(o)
# next(o)

#functional programming 

#map/reduce 
#map
# def f(x):
#     return x * x
# r = map(f, [1, 2, 3, 4, 5, 6, 7, 8, 9])
# print(list(r))
#reduce 
# from functools import reduce
# def add(x,y):
#     return x+y
# r = reduce(add, [1, 3, 5, 7, 9])
# print(r)


#filter
# def is_odd(n):
#     return n % 2 == 1
# L= list(filter(is_odd, [1, 2, 4, 5, 6, 9, 10, 15]))
# print(L)

#sort 
# print(sorted([1,56,23,63,56,3,5,8]))

#back a function 
# def lazy_sum(*args):
#     def sum():
#         ax = 0
#         for n in args:
#             ax = ax + n
#         return ax
#     return sum
# f = lazy_sum(1, 3, 5, 7, 9)
# print(f())


#lambda 
# L = list(map(lambda x: x * x, [1, 2, 3, 4, 5, 6, 7, 8, 9]))
# print(L)

#decorator
# def add():
#     print('add func ')
# f = add
# f()
# print(f.__name__)
# print(add.__name__)
# def log(func):
#     def wrapper(*args, **kw):
#         print('call %s()' % func.__name__)
#         return func(*args, **kw)
#     return wrapper
# def add():
#     print('add func ')

# log(add)()

# @log
# def mydel():
#     print('del func ')
# mydel()


