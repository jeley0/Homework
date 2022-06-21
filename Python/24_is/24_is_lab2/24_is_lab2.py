# Строки
# Делаем срезы
a = input()
print(a[2])  # 3-й символ
print(a[-2])  # Предпоследний
print(a[:5])  # Первые 5
print(a[:-2])  # Кроме 2-х последних
print(a[::2])  # Чётные индексы
print(a[1::2])  # Нечётные индексы
print(a[::-1])  # Обратный порядок
print(a[::-2])  # Обратный порядок через 1
print(len(a))  # Длина строки

# Две половинки
a = input()
print(a[(len(a) + 1) // 2:] + a[:(len(a) + 1) // 2])

# Обращение фрагмента
n = input()
a = n[:n.find('h')]
b = n[n.find('h'):n.rfind('h') + 1]
c = n[n.rfind('h') + 1:]
print(a + b[::-1] + c)

# Первое и последнее вхождения
a = input()
if a.count('f') == 1:
    print(a.find('f'))
elif a.count('f') > 1:
    print(a.find('f'), a.rfind('f'))

# Списки
# Больше предыдущего
a = [int(i) for i in input().split()]
for i in range(1, len(a)):
    if a[i] > a[i - 1]:
        print(a[i])

# Соседи одного знака
a = [int(i) for i in input().split()]
for i in range(1, len(a)):
    if a[i - 1] * a[i] > 0:
        print(a[i - 1], a[i])
        break

# Переставить соединение
a = [int(i) for i in input().split()]
for i in range(1, len(a), 2):
    a[i - 1], a[i] = a[i], a[i - 1]
print(' '.join([str(i) for i in a]))

# Уникальные элементы
a = [int(s) for s in input().split()]
for i in range(len(a)):
    for j in range(len(a)):
        if i != j and a[i] == a[j]:
            break
    else:
        print(a[i], end='\n')

# Ферзи
n = 8
x = []
y = []
correct = True

for i in range(0, n):
    x_input, y_input = [int(line) for line in input().split()]
    x.append(x_input)
    y.append(y_input)

for i in range(n):
    for j in range(i + 1, n):
        if x[i] == x[j] or y[i] == y[j] or abs(x[i] - x[j]) == abs(y[i] - y[j]):
            correct = False

if correct:
    print('NO')
else:
    print('YES')
