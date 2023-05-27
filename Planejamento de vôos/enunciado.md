# Planejamento de Vôos
O católogo da companhia aérea Voe Bem consiste em uma lista de vôos entre pares de cidades. Uma viagem consiste de um conjunto de vôos. Duas companhias aéreas são equivalentes se oferecerem conexões entre os mesmos pares de cidades, independentemente do número de escalas entre elas.

Uma outra companhia aérea, de nome Voe Livre, acabou de publicar seu catálogo do vôos. Assim, dados os catálogos da Voe Bem e da Voe Livre, determine se os mesmos são equivalentes ou não.

## Entrada
A entrada inicia por um inteiro 0 ≤ C ≤ 10, indicando o número de casos de teste a ser considerado. Na próxima linha, indica-se o número de vôos da empresa Voe Bem, denotado por 0 ≤ A ≤ 500. As próximas A linhas são compostas, cada uma, por dois inteiros, indicando a origem e o destino de cada vôo.

A linha A + 2 corresponde ao número de vôos da empresa Voe Livre, denotado pelo inteiro 0 ≤ B ≤ 500. As próximas B linhas são compostas, cada uma, por dois inteiros, indicando a origem e o destino de cada vôo.

Considera-se que cada empresa atenda, no máximo, 100 locais distintos que podem servir de origem/destino.

## Saída
Para cada caso de teste, se os catálogos de vôos de ambas as emrpesas são equivalentes, deve-se imprimir o inteiro 1. Caso contrário, deve-se imprimir o inteiro 0. A saída de cada caso de teste deve ser feita em uma linha separada.