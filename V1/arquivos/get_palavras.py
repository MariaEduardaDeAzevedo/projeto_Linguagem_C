#coding: utf-8
import requests
import json
from time import sleep

dic = open("dicionario.txt", "r")
controle = dic.readlines()

for i in range(len(controle)):
    if controle[i] == "assentar\n":
        print(i)
        break

dic.close()
