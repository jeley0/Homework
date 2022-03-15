# Номер появления слова

counter = {}
for word in input().split():
    counter[word] = counter.get(word, 0) + 1
    print(counter[word] - 1, end=' ')
print(end='\n')

# Словарь синонимов

n = int(input())
synonym = {}
for i in range(n):
    first, second = input().split()
    synonym[first] = second
    synonym[second] = first
print(synonym[input()])

# Выборы в США

num_votes = {}
for _ in range(int(input())):
    candidate, votes = input().split()
    num_votes[candidate] = num_votes.get(candidate, 0) + int(votes)

for candidate, votes in sorted(num_votes.items()):
    print(candidate, votes)

# Права доступа

ACTION = {
    'read': 'R',
    'write': 'W',
    'execute': 'X',
}

file_system = {}
n = int(input())

for i in range(n):
    file, *actions = input().split()
    file_system[file] = set(actions)

for i in range(int(input())):
    action, file = input().split()
    if ACTION[action] in file_system[file]:
        print('OK')
    else:
        print('Access denied')

# Частотный анализ

from collections import Counter

words = []
for _ in range(int(input())):
    words.extend(input().split())

counter = Counter(words)
pairs = [(-pair[1], pair[0]) for pair in counter.most_common()]
words = [pair[1] for pair in sorted(pairs)]
print('\n'.join(words))
