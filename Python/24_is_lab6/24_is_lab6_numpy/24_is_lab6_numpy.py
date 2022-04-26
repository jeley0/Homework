from PIL import Image
import numpy as np

# 1
# a
arr_1 = np.full((3, 4), 3)
print('a)', arr_1)

# b
arr_2 = np.random.randint(0, 9, size=(2, 4))
print('b)', arr_2)

# c
print('c)', arr_1.size, arr_2.size)

# d
print('d)', np.row_stack((arr_1, arr_2)))

# e
arr_3 = np.array([1, 8, 6, 5, 8, 3])
print('e)', arr_3)

# f
arr_4 = arr_3 * 3 + 1
print('f)', arr_4)

# g
arr_5 = arr_3.reshape((2, 3))
print('g)', arr_5)

# h
print('h)', np.min(arr_5, 1))

# i
print('i)', np.mean(arr_5))

# j
arr_6 = np.square(np.arange(11))
print('j)', arr_6)

# k
print('k)', arr_6[::2])

# l
print('l)', arr_6[::-1])

# m
arr_6[::2] = 2
print('m)', arr_6)

# n
print('n)', 49 in arr_6)

# o
a = np.random.randint(-10, 10, size=(4, 5))
b = a[a < 0]
print('o) (a)', a)
print('o) (b)', b, '\n')


# 2
def make_field(size):
    chess = np.zeros((size, size), dtype='int8')
    chess[size % 2::2, ::2] = 1
    chess[(size + 1) % 2::2, 1::2] = 1
    return chess


print(make_field(8), '\n')


# 3
def super_sort(rows, cols):
    arra = np.random.randint(1, 101, (rows, cols))
    arrb = arra.copy()
    arrb[:, ::2] = -np.sort(-arrb[:, ::2], axis=0)
    arrb[:, 1::2] = np.sort(arrb[:, 1::2], axis=0)
    return arra, arrb


print(super_sort(4, 5), '\n')


# 4
def bw_convert(url):
    image = Image.open(url)
    array = np.asarray(image, dtype='uint8')
    k = np.array([0.2989, 0.587, 0.114])
    width, height, _ = array.shape
    array.reshape(width * height, 3)
    out = np.matmul(array, k)
    out.reshape(width, height)
    image_out = Image.fromarray(out.astype(np.uint8))
    image_out.save("result.jpg")


bw_convert("kotik.jpg")


# 5
table = np.genfromtxt('ABBREV.csv', delimiter=';', dtype=None, names=True, encoding="utf8")
kcal = []
sugar = []
protein = []
vitamin = []

maximum = 0
for i in range(len(table)):
    if table[i][3] >= maximum:
        maximum = table[i][3]
        kcal = table[i][1]

maximum = 999
for i in range(len(table)):
    if table[i][9] < maximum:
        maximum = table[i][9]
        sugar = table[i][1]

maximum = 0
for i in range(len(table)):
    if table[i][4] > maximum:
        maximum = table[i][4]
        protein = table[i][1]

maximum = 0
for i in range(len(table)):
    if table[i][20] > maximum:
        maximum = table[i][20]
        vitamin = table[i][1]

print(kcal)
print(sugar)
print(protein)
print(vitamin)
