#include <vector>

using namespace std;

class Solution {
public:

    //Quando a função recursion é chamada com um valor n, ela verifica se dp[n] já foi calculado anteriormente e armazenado no vetor dp. 
    //Se sim, ela simplesmente retorna esse valor armazenado, evitando a necessidade de recalcular.
    int recursion(int n, vector<int> &dp){
        //Se n for menor que 2, a função retorna n
        if(n < 2){
           return n;
        }

        //Se n for igual a 2, a função retorna 1
        if(n == 2){
            return 1;         
        }

        //Se o valor para n já estiver armazenado no vetor dp, a função retorna esse valor.
        if(dp[n] != -1){
            return dp[n];
        }

        //Calcula o valor de dp[n] como a soma dos três valores anteriores de dp (recursivamente).
        return dp[n] = recursion(n - 1, dp) + recursion (n-2, dp) + recursion(n-3, dp);


    }

    int tribonacci(int n) {
        //Cria o vetor e inicializa com -1 cada uma das posicoes
        vector<int> dp(n+10, -1); 
        dp[0] = 0;

        return recursion(n, dp);
    }
};