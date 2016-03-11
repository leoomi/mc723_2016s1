#Exercicio 1
Leo Yuuki Omori Omi

1. É possível especificar optimizações no GCC utilizando a flag O, com diferentes opções, das quais foram usadas os opções de 0 a 3. 
Devido a falta de controle na alocação de recursos do sistema operacional para nosso programa, foram obtidos resultados variados em tempo real dentro de cada uma das opções de otimização, especialmente devido ao longo tempo de execução das funções de saída como mostrado pelo programa time, o que não é muito conclusivo. Em tempo real mostrado pelo programa, não é possível observar uma diferença significativa devido à precisão de 3 casas decimais dada como saída.
Mas como algumas das opções priorizam tempo de execução, tamanha de código ou tempo de compilação, mas como estamos mais interessados em tempo de excecução, faz sentido usar o opção -O3 que deveria resultar no menor tempo de execução.

'''shell
gcc primo.c -o primo -O3
'''

2. O GCC possui opções para otimizar os código gerado para arquiteturas específicas com as opções mtune ou march, sendo que a segunda inclui a primeira. Podemos utilizar a opção native para otimizar o código para a mesma arquitetura do processador que está compilando o código.

'''shell
gcc primo.c -o primo -O3 -march=native
'''

Novamente, o mesmo problema do item 1 ocorreu, e não é possível observar uma diferença significativa utilizando esta otimização.

3. A principal diferença entre criar um script que compila programas e um Makefile, é que caso escrito corretamente, usando Makefile, apeans os arquivos modificados precisam ser compilados novamente, então caso tenhamos muitos arquvios .c e apenas um arquivo tenha sido modificado, o Makefile deveria compilar mais rápido do que o script. Testando na minha máquina, foi possível obervar uma pequena melhora no tempo de execução do programa quando separado em dois arquivos, mas não houveram diferenças entre o programa compilado por script e o programa compilado por Makefile. Utilizando as otimizações na compilação, causou uma pequena melhora no tempo de execução como o esperado.

No caso de um arquivo compilado com as flags O3 e march=native, foram obtidos tempos variando de 0.347s a 0.380s.
No caso separado em dois arquivos sem flags de otimização os tempos foram de 0.334s a 0.354s.
No caso separado em dois arquivos e compilado com as mesmas flags, os resultados variaram entre 0.325s a 0.341s.

Agora com o programa modificado para calcular quantos números primos existem de 1 a n, calculando com n = 100000, obtivemos os seguintes resultados:
Um arquivo fonte: 1.375s a 1.425s
Dois arquivos fontes: 1.372s a 1.407s
Diferentemente do caso anterior, não houve uma diferença muito perceptível no tempo de execução entre os dois testes, sendo que a pequena diferença possa ter sido apenas resultado do acaso. 

Com a mudança do programa fazendo com que o laço da função apenas varra números números impares, o tempo de execução praticamente não muda. O que faz sentido considerando que a maior gargalo do algoritmo é no loop dentro da função primo, assim diminuir a quantidade de números testados não diminui muito a qunatidade de laços que são rodados dentro da funcção.

4. Depurar um programa é o processo de procurar e resolver bugs ou defeitos no código. que impedem o programa a rodar corretamente.

5. O GDB pode ser executado simplesmente escrevendo:
'''shell
gdb primo
'''
Escrevendo o nome do programa carrega o programa diretamente no depurador, sendo possível executar só o gdb e carregar o programa desejado.

6. É possível utilizar um ambiente gráfico com o GDB utilizando o programa DDD, ou até executando o gdb dentro do emacs, que já dá uma ajuda visual a mais do que o gdb diretamente da shell.

7.Para descobrir a parte mais executada do programa, podemos utilizar o grpof, que consegue desenhar o perfil de gasto de tempo do programa e aponta as funções que gastam mais tempo. No caso deste programa, como esperado, a maior parte do tempo de execução é gasto na função primo().

8. Primeiramente, para utilizar o gprof é necessário compilar o programa com a flag pg. Então, é necessário rodar o programa normalmente. Após ser executado, é possível obter os resultados utilizando, como exemplo este comando:
'''shell
 gprof primo > teste1
'''
No caso, obtemos o resultado do programa primo, que foi armazenado no arquivo teste1.

9. Para melhorar o programa, podemos utilizar o OpenMP, paralelizando principalmente o laço que chama função primo. Dividindo o trabalho em várias threads, foi possível observar uma significante redução do tempo de execuçao para n = 1000000, obtivemos um tempo de 1m55.796s para o programa sequencial e 37.648s. O que é uma melhora esperada com um processador de 4 núcleos.
