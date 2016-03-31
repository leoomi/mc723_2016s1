#Relatório do Projeto 1 MC833
##Leo Yuuki Omori Omi RA:138684
##Avaliação geral dos benchmarks
Para ordernar os computadores em ordem de desempenho considerando diversos benchmarks, é razoável utilizar o tempo de execução como parâmetro, já que um medida reazliada em todos os benchmarks, e é um número já importante.
Foram desconsiderados alguns tempo em formatos peculiares (com erros na própria medida de tempo por exempl), e alguns dos computadores foram descartados da lista, por terem executados pouco benchmarks, o que causa problemas na ordenação pelo pequeno espaço amostral.

Segue a lista em ordem descrescente em desempenho.

1. Pedro Meireles
2. João Fidélis
3. Renan Gomes
4. Klaus Rollman
5. Gabriel Bueno
6. Matheus Figueiredo
7. debios
9. Pedro Grijó
10. Matheus Pinheiro
11. Mateus Ruivo
12. Luiz Sekijima
13. Gabriel Magalhães
14. Gustavo Basso
15. Victor Souza
16. yk0 - Yugo Kuno
17. Wendrey
18. Cygnus X-1
19. Renan Castro
20. Rodrigo Silva
21. IC301-Titan
22. Bruno Hori - Mamonas
23. floyd
24. Netbook - Felipe Emos
25. Pedro Vasconcellos

É possível observar que os resultados são coerentes, considerando as especificações das máquinas nas primeiras colocações. Os processadores dessas máquinas são todos Intel Core i7, sendo que o processador do primeiro colocado tem um clock de 3.30GHz, que é o mais altos entre todos os processadores do tipo. Podemos notar também que os primeiros colocados possuem processadores mais recentes do que os computadores mais à baixo.
Já as máquinas nas últimas colocações, possuem processadores voltados a máquinas móveis (ARM Cortex-A7 e Intel Atom), que são processadores de baixa performance, e de fato, mostram resultados coerentes.

##Avaliação com os benchmarks do Grupo
###Convolução
O benchmark de convoluções foi o criado pelo o grupo no qual participei para a primeira parte do projeto. Ordenando primeiramente por tempo, os computadores que rodaram o benchamrk obtemos:

1. Titouan Thibaud
2. Gabriel Magalhães
3. Cygnus X-1
4. Klaus Rollman
5. Gabriel Bueno
6. yk0 - Yugo Kuno
7. Wendrey
8. Gustavo Basso
9. debios
10. Renan Castro
11. Victor Souza

Assim como no geral, podemos ver que os processadores da série Core I7 da Intel dominaram as primeiras colocações, sendo que a máquina com o clock mais alto de 3.00GHz de fato ficou em primeiro lugar. Este benchmark é paralelizado e demosntra melhor performace em processadores com mais threads, o que favorece os processadores i7, que possuem a tecnologia de Hyper-threading da Intel. O último colocado é coerente com esta afirmação já que é uma máquina com Intel Core 2 Quad CPU, que não possui essa tecnologia e é um modelo mais antigo.
Podemos notar também que a máquina Gabriel Magalhães e Cygnus X-1, tem quase as mesmas especificações, com a diferença de um SSD. No entanto, apesar de dar uma desempenho melhor, houve pouca diferença da performance de escrita no disco e os resultados foram muito similares apesar de uma forma mais rápida de armazanamento, o que indica que a leitura em disco não foi um grande gargalo para este benchmark, o que é reforçado pelas medidas do primeiro colocado, que obteve medidas piores em relação à escrita e leitura de disco comparado com as máquinas logo à baixo.

###imagemagick
Os dados colocados na planilha parecem estar incoerentes. Em certos casos computadores mais potentes tem tempos mais altos que computadores, e o contrário também ocorre. Portanto ordenaremos os computadores pelo menor tempo dos 4 testes realizados pelo benchmark.

1. Titouan Thibaud
2. Cygnus X-1
3. Gabriel Magalhães
4. yk0 - Yugo Kuno
5. IC301-Titan
6. IC-legiao
7. IC-sepultura
8. Netbook - Felipe Emos

Dentre os computadores em comum entre este benchmark e o de Convoluções, podemos ver colocações relativas semelhantes (Cygnus X-1, Gabriel Magalhães, Titouan Thibaud e yk0). Fora comentários já ditos em partes anteriores não há muito a se conclui, já que os dados inseridos na planilha não estão uniformes para cada medida, já que o dado incorreto foi colocado.

###fftw
Ordenando os computadores em relação ao dois tempos médios obtemos a seguinte lista:

1. João Paulo
2. Matheus Figueiredo
3. Cygnus X-1
4. Gustavo Basso
5. Rafael Faria
6. Bruno Hori - Mamonas
7. Mateus Ruivo

Como nos resultados anteriores, vemos os processadores i7 nas primeiras colocações, sendo o sexto colocado um outro computador Intel Quad Core, que novamente se esperaria ter menor performance. Podemos notar que há uma certa incosistência no primeiro colocado, com processador Intel(R) Core(TM) i7-4510U CPU @ 2.00GHz um modelo mais velho e com clock mais baixo que o segundo colocado, um Intel Core i7-4700HQ CPU @ 2.4GHz. Seria possível atribuir esta discrepância com alguma situação pontual fora de controle do benchamark que possivelmente afetou o segundo colocado.
Observa-se que a máquina de Mateus ruivo obteu um resultado extremamente fora da curva para a primeira medida neste benchmark, o que a deixou na última colocação.

##Conclusão
Dentre os 3 testes do grupo pudemos notar benchmarks e medidas que se concentravam principalmente na performace do processador. Podemos ver que modelos mais recentes, tem performance melhor como seria esperado, e que a frequência do clock faz diferença entre os modelos semelhantes. O mesmo pode ser observado na avaliação geral.