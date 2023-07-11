# Exercício *1286* do *BeeCrowd*: *Motoboy*

[**Link do Problema**](https://www.beecrowd.com.br/judge/en/problems/view/1286)

## Código comentado

```
# Função iterativa responsável por buscar o maior tempo (que, no contexto do 
# exercício, seria o "valor" de cada entrega).
# No caso, N representa a quantidade de elementos (número de entregas, cada
# uma com seus atributos) e P representa a quantidade máxima de pizzas
# que podem ser entregues (que, na ideia do knapsack, seria o peso máximo que a 
# mochila suportaria).

def knapsack (N, P, tempo, quantidade, memoization):

    # Passando por todas as linhas (que representam os elementos/entregas)
    for i in range(1, N+1):
        # Passando por todas as colunas (que representam os pesos/quantidades)
        for p in range(1, P+1):
            if ( quantidade[i] > p ): 

                # Se a qtd de pizzas exceder o valor máximo, repete-se o elemento da linha de cima
                memoization[i][p] = memoization[i-1][p]

            else:
                # Caso a qtd de pizzas não exceda o valor máximo, salvamos o maior valor dentre as duas opções:
                # - Repetir o valor do elemento da linha de cima;
                # - Somar o valor/tempo caso se "aceite realizar a entrega" e verificar o valor do elemento da linha superior
                # e da coluna com peso/quantidade reduzida da quantidade atual de pizzas;
                memoization[i][p] = max(
                    memoization[i-1][p],
                    tempo[i] + memoization[i-1][p - quantidade[i]]
                )
    
    # Retornamos o maior tempo/valor possível, que está armazenado no elemento da
    # última linha e coluna da matriz de memoização
    return memoization[N][P]

def main():

    # Número de elementos/entregas possíveis
    N = int(input())

    # O programa deve suportar inúmeros casos de teste, que só se
    # encerram quando o valor de N for igual a 0.
    while ( N > 0 ):

        # Número máximo de pizzas a serem entregues
        P = int(input())

        tempo = [0]
        quantidade = [0]
        memoization = []

        # Para cada entrega a ser feita, há dois atributos a serem considerados:
        # - O tempo que leva cada entrega (no contexto do knapsack, seria o valor
        # de cada entrega - que deve ser maximizado na solução);
        # - A quantidade de pizzas que aquela entrega possui (no contexto do knapsack, 
        # seria o "peso" de cada entrega, sendo que o peso máximo seria o valor de P).

        for _ in range(N):
            entry1, entry2 = map(int, input().split())
            tempo.append(entry1)
            quantidade.append(entry2)

        # Inicializando a matriz de Memoization com N+1 linhas e P+1 colunas,
        # sendo que os valores iniciais serão:
        # - Primeira linha com todos os valores iguais a 0;
        # - Primeira coluna com todos os valores iguais a 0;
        # - Demais valores da matriz inicializados com -1;

        memoization = [[-1 for _ in range (P+1)] for _ in range(N+1)]
        for ind in range(N+1): memoization[ind][0] = 0
        for ind in range(P+1): memoization[0][ind] = 0

        # Passando os valores recebidos para o knapsack, que retornará o tempo máximo para
        # cada caso de teste
        max_time = knapsack(N, P, tempo, quantidade, memoization)

        print(max_time, "min.")

        N = int(input())

    return 0

main()
```
