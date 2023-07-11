def knapsack (N, P, tempo, quantidade, memoization):

    for i in range(1, N+1):
        for p in range(1, P+1):
            if ( quantidade[i] > p ): 
                memoization[i][p] = memoization[i-1][p]
            else:
                memoization[i][p] = max(
                    memoization[i-1][p],
                    tempo[i] + memoization[i-1][p - quantidade[i]]
                )
    
    return memoization[N][P]

def main():

    N = int(input())

    while ( N > 0 ):
        P = int(input())

        tempo = [0]
        quantidade = [0]
        memoization = []

        for _ in range(N):
            entry1, entry2 = map(int, input().split())
            tempo.append(entry1)
            quantidade.append(entry2)

        memoization = [[-1 for _ in range (P+1)] for _ in range(N+1)]
        for ind in range(N+1): memoization[ind][0] = 0
        for ind in range(P+1): memoization[0][ind] = 0

        max_time = knapsack(N, P, tempo, quantidade, memoization)

        print(max_time, "min.")

        N = int(input())

    return 0

main()