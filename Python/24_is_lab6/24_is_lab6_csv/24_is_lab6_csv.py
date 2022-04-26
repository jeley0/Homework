import csv


# 12
with open('product.csv', 'r') as file:
    reader = csv.DictReader(file, delimiter=';')
    for line_dict in reader:
        old = int(line_dict['Old price'])
        new = int(line_dict['New price'])
        if old > new:
            print(line_dict['Name'])


# 13
d = {}
s, cl = input().split()
with open('rez.csv', encoding='utf-8') as file:
    reader = csv.reader(file, delimiter=',')
    for i in list(reader)[1:]:
        info = i[2].split('-')
        name = i[1].split()[3]
        score = int(i[-1])
        if int(s) == int(info[2]) and int(cl) == int(info[3]):
            if str(score) not in d:
                d[str(score)] = []
            d[str(score)].append(name)
for i in d:
    d[i].sort(reverse=True)
d = list(d.items())
d.sort(key=lambda i: int(i[0]), reverse=True)
for key, val in d:
    for i in val:
        print(i, key)
