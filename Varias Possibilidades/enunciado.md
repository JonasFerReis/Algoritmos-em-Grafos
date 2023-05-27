# Várias possibilidades
Antônio é um Engenheiro de Produção, e trabalha no controle de produção de uma planta automobilística em Picassent, região metropolitana de Valência, Espanha.

A empresa de Antônio passa por uma reestruturação de processos produtivos. Devido à experiência de Antônio em linhas de montagem, esse engenheiro foi escolhido para delinear o workflow dos novos produtos a serem comercializados pela montadora.

O fluxograma criado por Antônio representa as atividades, e suas relações nas etapas produtivas. Se existir, por exemplo, uma seta da Atividade 1 para a Atividade 3, então significa que a Atividade 3 necessita da finalização da Atividade 1 para que aquela dê início. O fato é que a montagem dos veículos da planta gerenciada por Antônio possui várias possibilidades de ser efetuada.

A partir de um trabalho de prospecção de características dos elementos que fazem parte da linha, Antônio chegou a um modelo de workflow final. Para a sumarização de seus dados em um dashboard, o engenheiro deseja contar o número de possibilidades de sequenciamento de atividades que começam da Atividade 1 até a(s) atividade(s) que representa(m) a finalização de uma etapa produtiva do veículo, indicada(s) pela(s) atividade(s) que não possui(em) alguma outra que depende dela(s).

Sua tarefa consiste em desenvolver um algoritmo que retorne a informação que Antônio necessita.

## Entrada
A primeira linha da entrada consiste em um número inteiro, n (n=50,100,1000), que indica a quantidade de atividades da linha de montagem. As próximas linhas representam as dependências diretas entre as atividades, em que se os elementos i e j (0 < i,j <= n) aparecerem na linha, então a Atividade j depende da Atividade i. A leitura termina quando os valores -1 -1 aparecem em uma linha.

O workflow delineado por Antônio não admite possiblidade de dependência cíclica entre as atividades.

## Saída
Um número inteiro, que representa o número de possibilidades de sequenciamento de atividades que começam da Atividade 1 até a(s) atividade(s) que representa(m) a finalização de uma etapa produtiva do veículo.