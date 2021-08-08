import random

arquivo = open('vetor5-caso4.txt', 'w')

lista = []
i = 0

for x in range(20):
    for k in range(11250):
        lista.insert(i, x)
        i = i + 1

random.shuffle(lista)

print('')
i = 0
for x in range(20):
    for k in range(11250):
        #print('{} ', lista[i])
        arquivo.write(str(lista[i]) + ' ')
        i += 1
