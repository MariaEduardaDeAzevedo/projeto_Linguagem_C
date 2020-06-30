# Corretor Ortográfico em Linguagem C

Este programa importa um dicionário de palavras em português e corrige textos digitados na entrada ou importados de um arquivo de texto (.txt) de acordo com a palavra mais parecida encontrada. 

### Detalhes do funcionamento

#### 1. Execução e Entrada
Para executar o programa, podemos chamar apenas ./main, como podemos ver na imagem abaixo:

![Imagem 1. Executando com ./main](https://raw.githubusercontent.com/MariaEduardaDeAzevedo/projeto_Linguagem_C/master/arquivos/imgs/Captura%20de%20tela%20de%202020-06-30%2009-51-33.png?token=AHDIVVT2UDCMO2FTD2YRBLK7ARZH6)

![Imagem 2. Escolhendo a opção 1.](https://raw.githubusercontent.com/MariaEduardaDeAzevedo/projeto_Linguagem_C/master/arquivos/imgs/Captura%20de%20tela%20de%202020-06-30%2009-52-16.png?token=AHDIVVXN3PVHONGHWFHY64S7ARZQQ)

![Imagem 3. Exemplo de correção.](https://raw.githubusercontent.com/MariaEduardaDeAzevedo/projeto_Linguagem_C/master/arquivos/imgs/Captura%20de%20tela%20de%202020-06-30%2009-52-27.png?token=AHDIVVQPNNX2HNGFPF4ZYKK7ARZWG)

Podemos também informar os argumentos diretamente em linha de comando.
A entrada segue um formato único:

```./main x argumento```

- O x acima indica o tipo de entrada que será dada, isto é, se você deseja digitar um texto direto na entrada ou se deseja importar de um arquivo. 

Para digitar na entrada (passando texto como argumento):

```./main 1 texto para ser corrigido```

Para importar de um arquivo (passando caminho do arquivo como argumento):

```./main 2 caminho_do_arquivo/nome_do_arquivo.txt```

Qualquer entrada fora desse padrão retornará um sinal de entrada inválida.

#### 2. Correção
Toda palavra que o programa não encontrar no dicionário, será dada como uma possível palavra errada e então serão dadas três opções de substituição da palavra, indicadas por 1, 2 e 3.
Quando desejar substituir a palavra, digite o número correspondente a ela, caso contrário, basta digitar 0 como entrada. 

#### 3. Correção em arquivo
Quando a sua entrada se tratar de um arquivo, você poderá optar entra corrigir diretamente o conteúdo desse ou apenas mostrar o texto corrigido em tela.

