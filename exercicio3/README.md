# Exercício 3
Leo Yuuki Omori Omi RA:138684

## Contando Instruções
Para a contagem da instrução add, foi modificado o arquivo mips_isa.cpp. Para tal, foi criado uma variável global adds, que é incrementada na função ac_behavior(add), ou seja deveria ser incrementada toda a vez que a instrução de add é executada. Para verificar o número, a funcão ac_behavior(end) imprime a variável global criada.
Ao executar este simulador, obtemos 0 instruções de add na execução do programa Hello World. De fato, podemos observar no objdump do programa que não existem instruções de add, apenas outra variantes como, addu e addui.