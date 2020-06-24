arq = open("V2/arquivos/dicionario.txt", "r")

lista = arq.readlines() 

for i in range(len(lista)):
    lista[i] = lista[i].lower()

arq.close()

arq = open("V2/arquivos/dicionario.txt", "w")
arq.write("")

arq.close()

arq = open("V2/arquivos/dicionario.txt", "a")

for i in range(len(lista)):
    arq.write(lista[i])

print(lista)

arq.close()