# Exercício *309* do *LeetCode*: *Best Time to Buy and Sell Stock with Cooldown*

[**Link do Problema**](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

## Código comentado

```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        # Primeiramente, inicializamos uma matriz 2 x 5005 para a memoização.
        # Nela, as linhas 0 e 1 representam os possíveis estados para cada operação,
        # onde se a linha em questão for a 1, é possível fazer uma compra e se a linha em
        # questão for a 0, não é possível fazer uma compra de ações.
        #
        # Em ambos os casos é possível realizar o cooldown e "saltar" uma coluna.
        #
        # Quanto às colunas, estas representam os índices dos preços passados na lista
        # prices. Isto é, a coluna 0 representa o valor de prices[0] e, considerando 
        # as linhas, se estivermos na linha 1, é possível comprar a ação.
        # Caso contrário, não é possível comprar a ação.
        #
        # Representação aproximada da matriz declarada (com 2 linhas e 5005 colunas):
        #
        # -1e9 -1e9 -1e9 -1e9 -1e9 -1e9 -1e9 -1e9 ... -1e9
        # -1e9 -1e9 -1e9 -1e9 -1e9 -1e9 -1e9 -1e9 ... -1e9

        Memoization = [[-1e9 for _ in range(5005)] for _ in range(2)]

        # Função recursiva responsável por ir avaliando todas as possíveis
        # ações para cada elemento do vetor prices: comprar (buy), vender (sell)
        # ou "pular" (cooldown).
        #
        # Vale ressaltar que aqui a variável canIBuy representa a linha da matriz de memoização
        # e a variável currentPrice representa a coluna da matriz de memoização e o índice
        # do preço atual da ação no vetor prices.

        def stockProfit(canIBuy: int, currentPrice: int):

            # A partir do momento que todos os valores de price 
            # forem avaliados, a recursão finaliza (condição de parada abaixo)

            if ( currentPrice >= len(prices) ): return 0 

            # Se o valor ótimo da posição já estiver salvo na memoização,
            # podemos apenas retorná-lo

            if(Memoization[canIBuy][currentPrice] != -1e9): return Memoization[canIBuy][currentPrice]

            # Se for possível fazer a compra de uma ação 
            # (i.e. se estivermos na linha 1 da matriz -> se canIBuy == 1)

            if (canIBuy): 

                # Nessa situação, podemos apenas fazer duas ações: realizar o cooldown ou
                # comprar uma ação, deduzindo seu valor armazenado em prices[currentPrice].
                # Verificamos qual a melhor opção e armazenamos na matriz de memoização, retornando o valor.

                Memoization[canIBuy][currentPrice] = max(
                    stockProfit(1, currentPrice + 1) - 0,
                    stockProfit(0, currentPrice + 1) - prices[currentPrice]
                )
                return Memoization[canIBuy][currentPrice]

            else:

                # Nessa situação, podemos apenas fazer duas ações: realizar o cooldown ou
                # vender a ação, somando seu valor armazenado em prices[currentPrice].
                # Verificamos qual a melhor opção e armazenamos na matriz de memoização, retornando o valor.

                Memoization[canIBuy][currentPrice] = max(
                    stockProfit(0, currentPrice + 1) + 0,
                    stockProfit(1, currentPrice + 2) + prices[currentPrice]
                )
                    
                return Memoization[canIBuy][currentPrice]

        # Aqui fazemos a chamada da função stockProfit com canIBuy igual a 1 e 
        # currentPrice igual a zero.
        #
        # O valor retornado representará o lucro máximo com a venda das ações de
        # acordo com as regras dadas pelo exercício.

        maximumProfit = stockProfit(1, 0)

        return maximumProfit
```
