# Corretor Ortográfico em Linguagem C

Este programa importa um dicionário de palavras em português e corrige textos digitados na entrada ou importados de um arquivo de texto (.txt) de acordo com a palavra mais parecida encontrada. 

### Detalhes do funcionamento

#### 1. Execução e Entrada
Para executar o programa, podemos chamar apenas ./main, como podemos ver na imagem abaixo:

![Imagem 1. Executando com ./main](https://raw.githubusercontent.com/MariaEduardaDeAzevedo/projeto_Linguagem_C/master/arquivos/imgs/Captura%20de%20tela%20de%202020-06-30%2009-51-33.png?token=AHDIVVT2UDCMO2FTD2YRBLK7ARZH6)
###### Executando com ./main


![Imagem 2. Escolhendo a opção 1.](https://raw.githubusercontent.com/MariaEduardaDeAzevedo/projeto_Linguagem_C/master/arquivos/imgs/Captura%20de%20tela%20de%202020-06-30%2009-52-16.png?token=AHDIVVXN3PVHONGHWFHY64S7ARZQQ)
###### Escolhendo digitar texto diretamente na interface


![Imagem 3. Exemplo de correção.](https://raw.githubusercontent.com/MariaEduardaDeAzevedo/projeto_Linguagem_C/master/arquivos/imgs/Captura%20de%20tela%20de%202020-06-30%2009-52-27.png?token=AHDIVVQPNNX2HNGFPF4ZYKK7ARZWG)
###### Exemplo de correção de palavra

![Imagem 4. Escolhendo a opção 2.](https://raw.githubusercontent.com/MariaEduardaDeAzevedo/projeto_Linguagem_C/master/arquivos/imgs/Captura%20de%20tela%20de%202020-06-30%2009-53-13.png?token=AHDIVVUEN6IYIWF5XRUJMTC7AR2EY)
###### Escolhendo importar conteúdo a ser corrigido de um arquivo

![Imagem 5. Alterando gravação do arquivo.](https://raw.githubusercontent.com/MariaEduardaDeAzevedo/projeto_Linguagem_C/master/arquivos/imgs/Captura%20de%20tela%20de%202020-06-30%2009-53-19.png?token=AHDIVVT5FGKOPT6YDZENMCS7AR2IC)
###### Alterando gravação do arquivo para texto corrigido


Podemos também informar os argumentos diretamente em linha de comando.
A entrada segue um formato único:

```./main x argumento```

- O x acima indica o tipo de entrada que será dada, isto é, se você deseja digitar um texto direto na entrada ou se deseja importar de um arquivo. 

Para digitar na entrada (passando texto como argumento):

```./main 1 texto para ser corrigido```

![Imagem 6. Exemplo de execução em linha de comando para texto digitado.](https://raw.githubusercontent.com/MariaEduardaDeAzevedo/projeto_Linguagem_C/master/arquivos/imgs/Captura%20de%20tela%20de%202020-06-30%2010-15-22.png?token=AHDIVVQAUGCRXJERVELGQGS7AR3L4)
###### Exemplo de execução na linha de comando digitando texto

Para importar de um arquivo (passando caminho do arquivo como argumento):

```./main 2 caminho_do_arquivo/nome_do_arquivo.txt```

![Imagem 7. Exemplo de execução em linha de comando para correção de arquivo.](https://raw.githubusercontent.com/MariaEduardaDeAzevedo/projeto_Linguagem_C/master/arquivos/imgs/Captura%20de%20tela%20de%202020-06-30%2010-15-53.png?token=AHDIVVVZORS3B4PKSYDGWI27AR3PG)
###### Exemplo de execução na linha de comando passando caminho do arquivo


Qualquer entrada fora desse padrão retornará um sinal de entrada inválida.

#### 2. Correção
Toda palavra que o programa não encontrar no dicionário, será dada como uma possível palavra errada e então serão dadas três opções de substituição da palavra, indicadas por 1, 2 e 3.
Quando desejar substituir a palavra, digite o número correspondente a ela, caso contrário, basta digitar 0 como entrada. 

#### 3. Correção em arquivo
Quando a sua entrada se tratar de um arquivo, você poderá optar entra corrigir diretamente o conteúdo desse ou apenas mostrar o texto corrigido em tela.


###### Na pasta arquivos você poderá encontrar um arquivo de texto (arquivo.txt) com um texto a ser corrigido como exemplo.
