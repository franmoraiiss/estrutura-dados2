import random
arquivo = open('vetor5-caso1.txt', 'w')

a_list = list(range(0, 255000))
random.shuffle(a_list)

for i in range(255000):
    arquivo.write(str(a_list[i]) + ' ')
    i += 1
