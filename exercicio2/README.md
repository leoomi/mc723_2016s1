#Exercício 2
Leo Yuuki Omori Omi RA: 138684

##Condições Experimentais
Para esta atividade foi escolhido a simulção de um programa com dois níveis de cache, sendo 2 caches L1, um de instruções e outro de dados, e uma L2 unificada. Dos 46 traces fornecidos, foi escolhido o gzip, sendo que há traces das primeiras 2 bilhões de instruções(F2B) e de 2 bilhões de instruções após 50 bilhões de instruções(M2B), a F2B foi escolhida.

##Experimento de Referência
Para melhor análise de melhora de desempenho da configuração de cache sugerida, foi escolhida um experimento de referência para comparação de dado:
L1 de instruções: 16KB, blocos de 16 bytes
L1 de dados: 16KB, blocos de 16 bytes
L2 unificado: 64KB, blocos de 32 bytes

Para tal, foi utilizado o seguinte comando:

'''
dinero4sbc/dineroIV -informat s -trname gzip_f2b -maxtrace 20 -l1-isize 16K -l1-ibsize 16 -l1-dsize 16K -l1-dbsize 16 -l2-usize 64K -l2-ubsize 32
'''

Para achar uma melhor configuração, manteremos o tamanho das caches e variaremos o tamanho do blocos e a associatividade para achcar uma configuração melhor. Usaremos principalmente as métricas de misses e fecthes fornecidas pelo dinero para analisar a performance do cache, sendo estes os dados deste experimento de referência:

'''
l1-icache
 Metrics                      Total           Instrn           Data            Read           Write            Misc
  -----------------            ------          ------          ------          ------          ------          ------
   Demand Fetches            399999987       399999987               0               0               0               0
   Fraction of total           1.0000          1.0000          0.0000          0.0000          0.0000          0.0000

   Demand Misses               7108932         7108932               0               0               0               0
   Demand miss rate            0.0178          0.0178          0.0000          0.0000          0.0000          0.0000


l1-dcache
 Metrics                      Total           Instrn           Data            Read           Write            Misc
  -----------------            ------          ------          ------          ------          ------          ------
   Demand Fetches            149493660               0       149493660       110618221        38875439               0
   Fraction of total           1.0000          0.0000          1.0000          0.7400          0.2600          0.0000

   Demand Misses              13508260               0        13508260         9059885         4448375               0
   Demand miss rate            0.0904          0.0000          0.0904          0.0819          0.1144          0.0000


l2-ucache
 Metrics                      Total           Instrn           Data            Read           Write            Misc
  -----------------            ------          ------          ------          ------          ------          ------
   Demand Fetches             27157942         7108932        20049010        13508260         6540750               0
   Fraction of total           1.0000          0.2618          0.7382          0.4974          0.2408          0.0000

   Demand Misses               9057136           35600         9021536         7515941         1505595               0
   Demand miss rate            0.3335          0.0050          0.4500          0.5564          0.2302          0.0000
'''

##Variando o tamanho do bloco
Variar o tamanha dos blocos, pode diminuir a taxa de miss na cache. Para testes, foi rodado uma simulação com o dobro de tamanaho de bloco para todos os caches e uma segunda simulação com o maior tamanho permitido. Omitiremos os resultados para não poluir o documento. Para o primeiro teste, foram obtidos resultados ligeiramente melhores, com exceção do cache L2, indicando que o tamanho de bloco deste cache pode estar bom. No entanto, para o segundo tes. Portanto um tamanho de bloco bom deve ser maior que o de referência, mas não muito maior.

Obtemos melhores resultados então para L1 de instruções com tamanho de bloco de 512 bytes, L1 de dados com blocos de 128 bytes e o L2 com blocos de 32 bytes:

'''
l1-icache
Metrics                      Total           Instrn           Data            Read           Write            Misc
 -----------------            ------          ------          ------          ------          ------          ------
 Demand Fetches            399999987       399999987               0               0               0               0
  Fraction of total           1.0000          1.0000          0.0000          0.0000          0.0000          0.0000

 Demand Misses               1521671         1521671               0               0               0               0
  Demand miss rate            0.0038          0.0038          0.0000          0.0000          0.0000          0.0000


l1-dcache
 Metrics                      Total           Instrn           Data            Read           Write            Misc
 -----------------            ------          ------          ------          ------          ------          ------
 Demand Fetches            145757531               0       145757531       108026579        37730952               0
  Fraction of total           1.0000          0.0000          1.0000          0.7411          0.2589          0.0000

 Demand Misses               7090500               0         7090500         5863731         1226769               0
  Demand miss rate            0.0486          0.0000          0.0486          0.0543          0.0325          0.0000


l2-ucache
 Metrics                      Total           Instrn           Data            Read           Write            Misc
 -----------------            ------          ------          ------          ------          ------          ------
 Demand Fetches             64708076        24346736        40361340        28362000        11999340               0
  Fraction of total           1.0000          0.3763          0.6237          0.4383          0.1854          0.0000

 Demand Misses              19212340          659412        18552928        16027224         2525704               0
  Demand miss rate            0.2969          0.0271          0.4597          0.5651          0.2105          0.0000
'''

O comando utilizado foi:
'''
dinero4sbc/dineroIV -informat s -trname gzip_f2b -maxtrace 20 -l1-isize 16K -l1-ibsize 512 -l1-dsize 16K -l1-dbsize 128 -l2-usize 64K -l2-ubsize 32
'''

##Variando a associatividade
Podemos realizar testes semelhantes com os experimentos de tamanho de bloco, desta vez testanto diferentes níveis de associatividade. Semelhantemente aos testes anteriores, iniciamos testes com uma simulação com associatividade de 2 e depois uma simulação com uma maior associatividade possível para cada cache. Para a cache L1 de instruções com associatividade 2, foram obtidos taxas de miss muito baixa de 0.0000 para a precisão do dinero, portanto esta configuração para este cache parace adequado. Para as outras 2 caches também houveram melhoras, mas de menor escala.
Para o segundo teste com a maior associatividade possível, houve uma melhora extremamente pequena para a L1 de instruções, uma piora para a L1 de dados, e resultados mistos para a L2.
Portanto sabemos que a L1 de instruções com associatividade 2 já tem uma boa performance. Após alguns testes, obtemos as seguintes configurações:
L1 de intruções com associatividade 2
L1 de dados com associatividade 4
L2 unificado com associatividade 8

Aumentar a associatividade do L1 de dados não causava uma melhora significativa após este ponto, e aumentar a associatividade de L2, começava a aumentar a taxa de miss de read, portanto foram escolhidas estas configurações.

##Resultado final
Obtemos então a melhor configuração de:
L1 de instruções: 16KB, blocos de 512 bytes e associatividade 2
L1 de dados: 16KB, blocos de 128 bytes e associatividade 4
L2 unificado: 64KB, blocos de 32 bytes e associatividade 8


Usando o comando:

'''
dineroIV -informat s -trname gzip_f2b -maxtrace 20 -l1-isize 16K -l1-ibsize 512 -l1-dsize 16K -l1-dbsize 128 -l2-usize 64K -l2-ubsize 32 -l1-iassoc 2 -l1-dassoc 4 -l2-uassoc 8
'''
Que dá o seguinte resultado:
'''
l1-icache
 Metrics		      Total	      Instrn	       Data	       Read	      Write	       Misc
 -----------------	      ------	      ------	      ------	      ------	      ------	      ------
 Demand Fetches		   399999987	   399999987	           0	           0	           0	           0
  Fraction of total	      1.0000	      1.0000	      0.0000	      0.0000	      0.0000	      0.0000

 Demand Misses		         685	         685	           0	           0	           0	           0
  Demand miss rate	      0.0000	      0.0000	      0.0000	      0.0000	      0.0000	      0.0000



l1-dcache
 Metrics		      Total	      Instrn	       Data	       Read	      Write	       Misc
 -----------------	      ------	      ------	      ------	      ------	      ------	      ------
 Demand Fetches		   145757531	           0	   145757531	   108026579	    37730952	           0
  Fraction of total	      1.0000	      0.0000	      1.0000	      0.7411	      0.2589	      0.0000

 Demand Misses		     5036412	           0	     5036412	     4306258	      730154	           0
  Demand miss rate	      0.0346	      0.0000	      0.0346	      0.0399	      0.0194	      0.0000


l2-ucache
 Metrics		      Total	      Instrn	       Data	       Read	      Write	       Misc
 -----------------	      ------	      ------	      ------	      ------	      ------	      ------
 Demand Fetches		    28864684	        2464	    28862220	    20145648	     8716572	           0
  Fraction of total	      1.0000	      0.0001	      0.9999	      0.6979	      0.3020	      0.0000

 Demand Misses		    14171924	        2396	    14169528	    14093932	       75596	           0
  Demand miss rate	      0.4910	      0.9724	      0.4909	      0.6996	      0.0087	      0.0000
'''

