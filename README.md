# Corretor Ortográfico Linguagem C

### Explicando a estrutura
- Fiz dois arquivos de cabeçalho para separar as funcionalidades.
- No arquivo algoritmos.h implementei alguns algoritmos úteis para o projeto.
- No arquivo imports.h estão as funções referentes à importação dos arquivos, dentre elas a que o professor nos enviou.
- No main.c (bem desorganizado, por sinal kkkkkk), eu importo o dicionário, importo o arquivo a ser corrigido, ordeno o dicionario e chamo uma função de correção que também está no main. 


### Maiores problemas
- O maior problema que eu encontrei foi realmente a estratégia de encontrar as palavras parecidas no array de palavras, pois está sendo muito lento. Tentei implementar um algoritmo de divisão e conquista, mas ele não foi muito preciso e a iterativa é muito lenta.

