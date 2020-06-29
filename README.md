# Corretor Ortográfico em Linguagem C

Este programa importa um dicionário de palavras em português e corrige textos digitados na entrada ou importados de um arquivo de texto (.txt) de acordo com a palavra mais parecida encontrada. 

### Detalhes do funcionamento

#### 1. Execução e Entrada
Para executar o programa, chamamos ./main, porém precisamos passar as entradas devidas.

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

