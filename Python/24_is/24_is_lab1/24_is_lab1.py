# 1
film = input()
place = input()
time = input()

print("Билет на \" " + film + " \" в \" " + place + " \" на " + time + " забронирован.")

# 2
a = input()
b = input()

if a == 'да' and b == 'да':
    print("ВЕРНО")
elif a == 'нет' and b == 'нет':
    print("ВЕРНО")
elif a == 'нет' and b == 'да':
    print("ВЕРНО")
elif a == 'да' and b == 'нет':
    print("ВЕРНО")
elif b != 'да' or b != 'нет' or a != 'да' or a != 'нет':
    print("НЕВЕРНО")

# 3
login = input()
email = input()

if "@" not in login and "@" in email:
    print("Верно")
else:
    print("Неверно")

# 4
print(input())

# 5
a = input()

if a == "":
    print("Да")
else:
    print("Нет")

# 6
number = int(input())

a = number // 100
b = number % 100 // 10
c = number % 10

if number < 100 or number > 999:
    print("Введите трехзначное число")
elif (a + c) // 2 == b:
    print("Вы ввели красивое число")
else:
    print("Жаль, вы ввели обычное число")

# 7
number = int(input())

a = number // 1000
b = number // 100 % 10
c = number // 10 % 10
d = number % 10

if a > b:
    a, b = b, a
if b > c:
    b, c = c, b
if c > d:
    c, d = d, c
if a > b:
    a, b = b, a
if b > c:
    b, c = c, b
if a > b:
    a, b = b, a
if a == 0 and b:
    a, b = b, a
elif a == 0 and c:
    a, c = c, a
elif a == 0 and d:
    a, d = d, a
if number < 1000 or number > 9999:
    print("Введите четырехзначное число")
else:
    print(d + 10 * (c + 10 * (b + 10 * a)))

# 8
growth = input()
n = 0
MIN = 190
MAX = 150

while growth != "!":
    growth = int(growth)
    if 150 <= growth <= 190:
        n += 1
        if growth >= MAX:
            MAX = growth
        if growth <= MIN:
            MIN = growth
    growth = input()
print(n)
print(MIN, MAX)

# 9
ok = False

while not ok:
    password1 = input()
    password2 = input()
    if len(password1) < 8:
        print("Короткий!")
    elif "123" in password1:
        print("Простой!")
    elif password1 != password2:
        print("Различаются.")
    else:
        ok = True

print("ОК")

# 10
x = "start"

while x != "x":
    number1 = int(input())
    x = input()
    if x == "+":
        print(number1 + int(input()))
    elif x == "-":
        print(number1 - int(input()))
    elif x == "*":
        print(number1 * int(input()))
    elif x == "/":
        number2 = int(input())
        if number2 != 0:
            print(number1 // number2)
    elif x == "%":
        number2 = int(input())
        if number2 != 0:
            print(number1 % number2)
    elif x == "!":
        if number1 >= 0:
            factorial = 1
            for i in range(2, number1 + 1):
                factorial *= i
            print(factorial)
    elif x == "x":
        print(number1)

# 11
n = int(input())

for i in range(1, 2 * n, 2):
    empty = " " * ((2 * n - 1 - i) // 2)
    print(empty + "*" * i + empty)

# 12
n = int(input())

q = 1
s = 1
k = 0
while q <= n:
    print(q, end=' ')
    q = q + 1
    k = k + 1
    if k == s:
        print()
        s = s + 1
        k = 0
print()

# 13
a = int(input())  # ширина
b = int(input())  # высота
symbol = input()

print(symbol * a)
for i in range(1, b - 1):
    print(symbol + " " * (a - 2) + symbol)
print(symbol * a)
