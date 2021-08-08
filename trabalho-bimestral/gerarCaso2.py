arquivo = open('vetor5-caso2.txt', 'w')

a_list = list(range(0, 255000))

for i in range(255000):
    arquivo.write(str(a_list[i]) + ' ')
    i += 1
