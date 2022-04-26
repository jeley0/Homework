import random


# 6
def random_line(afile):
    try:
        line = next(afile)
        for num, aline in enumerate(afile, 2):
            if random.randrange(num):
                continue
            line = aline
        print(line)
    except StopIteration:
        return


random_line(open("lines.txt"))

# 7
dictionary = {
    "й": "j", "ц": "c", "у": "u", "к": "k", "е": "e", "н": "n",
    "г": "g", "ш": "sh", "щ": "shh", "з": "z", "х": "h", "ъ": "#",
    "ф": "f", "ы": "y", "в": "v", "а": "a", "п": "p", "р": "r",
    "о": "o", "л": "l", "д": "d", "ж": "zh", "э": "je", "я": "ya",
    "ч": "ch", "с": "s", "м": "m", "и": "i", "т": "t", "ь": "'",
    "б": "b", "ю": "ju", "ё": "jo"
}

file = open('cyrillic.txt', encoding='utf8')
lines = file.readlines()
result = ''

for line in lines:
    for symbol in line:
        isUpper = symbol.isupper()
        temp = dictionary.get(symbol.lower(), symbol)
        if isUpper:
            temp = temp.capitalize()
        result = result + temp

file.close()
new_file = open('transliteration.txt', 'w', encoding='utf8')
new_file.write(result)
new_file.close()


# 8
def reverse():
    with open('input.dat', 'rb') as input_file:
        temp = input_file.read()
    with open('output.dat', 'wb') as out_file:
        out_file.write(temp[::-1])


reverse()

# 9
with open('input.txt', 'r') as input_file:
    temp = [int(i) for i in input_file.read().split()]

metka1 = []
metka2 = []
metka3 = []

for i in temp:
    if i > 0:
        metka1.append(i)
    elif i < 0:
        metka2.append(i)
    else:
        metka3.append(i)

with open('output.txt', 'w') as output_file:
    print(len(temp), file=output_file)
    print('1', len(metka1), '-1', len(metka2), '0', len(metka3), file=output_file)


# 10
with open('image.bmp', 'rb') as input_file:
    temp = bytes(input_file.read())

negativ = []
for i, elem in enumerate(temp):
    if i < 54:
        negativ.append(elem)
    else:
        negativ.append(255 - elem)

with open('output.bmp', 'wb') as output_file:
    output_file.write(bytes(negativ))
