O objetivo deste projeto é exercitar a manipulação de ponteiros em um cenário onde se exige a alocação dinâmica de memória através da implementação de um programa computacional.

Para a realização desta atividade, foi suposta a necessidade de cadastrar clientes de uma loja. Por ser uma loja nova e com produtos inovadores, pouco se sabe do mercado a ser atingido, sendo assim, não se sabe a quantidade de clientes poderão ser cadastrados. Estima-se, inicialmente, em 10 clientes. Cada cliente terá os seguintes
campos:

- nome (suponha um nome com, no máximo, 30 caracteres)

- ano de nascimento

- montante de gastos realizados no mês (quanto o clinte pagou em suas compras dentro do mês corrente)

Para tanto, o sistema oferecerá as seguintes funcionalidades:

- incluir um novo cliente

- remover cliente - atualizar o montante de compras do cliente realizadas no mês corrente

- zerar todos os montantes de compras por ocasião da virada de mês

- listar o cliente melhor comprador

- exibir um montante de compras de um cliente específico.

O programa prevê a situação que a quantidade de clientes a ser cadastrados supere a previsão inicial. Neste caso, quando o espaço de memória destinado a receber dados dos clientes estiver cheia, pode-se ampliar esse espaço – sempre em blocos de 10.
