# Кол-во различных чисел

print(len(set(input().split())))

# Кол-во совпадающих чисел

print(len(set(input().split()) & set(input().split())))

# Пересечение множества

print(*sorted(set(input().split()) & set(input().split()), key=int))

# Встречалось ли число раньше

numbers = [int(s) for s in input().split()]
occur_before = set()
for num in numbers:
    if num in occur_before:
        print('YES')
    else:
        print('NO')
        occur_before.add(num)

# Количество слов в тексте

words = set()
for i in range(int(input())):
    words.update(input().split())
print(len(words))
