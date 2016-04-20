# Exercício 3
Leo Yuuki Omori Omi RA:138684

## Contando Instruções
Para a contagem da instrução add, foi modificado o arquivo mips_isa.cpp. Para tal, foi criado uma variável global adds, que é incrementada na função ac_behavior(add), ou seja deveria ser incrementada toda a vez que a instrução de add é executada. Para verificar o número, a funcão ac_behavior(end) imprime a variável global criada.
Ao executar este simulador, obtemos 0 instruções de add na execução do programa Hello World. De fato, podemos observar no objdump do programa que não existem instruções de add, apenas outra variantes como, addu e addui. 
O compilador de MIPS para a linguagem C gera um códgio assembly sem utlizar a instrução add, pois C ignora overflows, por isso é utilizada a instrução addu, que não sinaliza overflows, sendo que a instrução add sinaliza.

## Avaliando Desempenho
Considerando meu RA (138684) foram executados os programas jpeg decoder(small), gsm coder(small) e gsm coder(large).Foram rodados os scripts inclusos utilizando o simulador gerado com o acsim usando a opção -s. A saída do simulador foi copiada para uma planilha do Google Sheets, e consideranco o CPI para cada tipo de intrução, foram somados os npumero de ciclos para cada instrução.
https://docs.google.com/spreadsheets/d/1nSf2rfUsF8OfAOqdIUI6pw4Jrq2vpPT9JYmEYHdKJyY/edit#gid=0

Obtemos então:



| Programa          | Ciclos         | 
| -------------     |:-------------:| 
|jpeg decoder(small)| 47876472      | 
|gsm coder(small)   | 33905889      |  
| gsm coder(large)  | 1840374462      |  
