class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        Memoization = [[-1e9 for _ in range(5005)] for _ in range(2)]

        def stockProfit(canIBuy: int, currentPrice: int):
            if ( currentPrice >= len(prices) ): return 0

            if(Memoization[canIBuy][currentPrice] != -1e9): return Memoization[canIBuy][currentPrice]

            if (canIBuy): 
                Memoization[canIBuy][currentPrice] = max(
                    stockProfit(1, currentPrice + 1) - 0,
                    stockProfit(0, currentPrice + 1) - prices[currentPrice]
                )
                return Memoization[canIBuy][currentPrice]
            else:
                Memoization[canIBuy][currentPrice] = max(
                    stockProfit(0, currentPrice + 1) + 0,
                    stockProfit(1, currentPrice + 2) + prices[currentPrice]
                )
                    
                return Memoization[canIBuy][currentPrice]

        maximumProfit = stockProfit(1, 0)

        return maximumProfit