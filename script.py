open_list = open("arquivos/sort_dict.txt", "r")

lista = open_list.readlines()
lista.sort()

write_list = open("arquivos/sort_dict.txt", "w")
write_list.write("")
write_list.close()

write_list = open("arquivos/sort_dict.txt", "a")
for e in lista:
    print(e)
    write_list.write(e)

open_list.close()
write_list.close()
