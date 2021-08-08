arquivo = open('vetor5-caso3.txt', 'w')

a_list = list(range(0, 255000))
a_list.sort(reverse=True)

for i in range(255000):
    arquivo.write(str(a_list[i]) + ' ')
    i += 1
