# Pontos dominantes

O administrador da Rede de Transportes da cidade de São Pedro adquiriu um sistema de tecnologia da informação que auxilia no gerenciamento do tráfego de veículos. Uma das funcionalidades do sistema consiste na identificação de pontos da rede denominados pontos dominantes, definidos pelo gestor da rede através dos seguintes conceitos.

- O ponto 0 (zero) é considerado o ponto origem.
- Um ponto X domina um ponto Y se qualquer caminho do ponto origem ao ponto Y passa por X.
- Se um ponto Y não é alcançável a partir da origem, então Y não possui pontos que o dominam.
- Por conveniência, o gestor do sistema determinou que todo ponto alcançável a partir do ponto de origem domina ele mesmo. Além disso, o ponto de origem sempre domina ele mesmo.

O cálculo dos pontos dominantes implementado no sistema gasta muito tempo computacional. Diante disso, sua tarefa consiste em implementar um algoritmo eficiente que determine todas relações de "dominância" entre cada par de pontos da rede de transportes.

## Entrada
A primeira linha do arquivo de teste contém o número de estações da rede, denotado por N (0 < N < 100). As próximas N linhas são compostas por N colunas. Se existe o número 1 na linha u e coluna v, então existe uma ligação direta entre a estação u e a estação v.

Observação: note que o fato de existir uma via que provê o deslocamento de um veículo do ponto u para o ponto v não implica na possibilidade do mesmo veículo se deslocar diretamente de v para u.

## Saída
Uma representação de N linhas, em que cada linha representa uma estação e os números impressos na linha em questão indicam as estações a qual ela domina. Caso uma dada linha não tenha estações dominadas, o valor a ser impresso deve ser "-".

Observação: cuidado com espaços em branco e linhas impressas a mais.