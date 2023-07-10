#include <bits/stdc++.h>

using ll = long long int;
using namespace std;

ll solve(vector<ll> coins, ll n, ll x){
    vector<ll> dp(x+10);

    for (ll i = 1; i <= x; i++)
    {
        //O vetor é inicializado com um valor máximo (INT_MAX) para cada posição
        //O vetor dp[i] representa o número mínimo de moedas necessárias para obter a soma exata de i.
        dp[i] = INT_MAX;

        for (ll j = 0; j < n; j++)
        {
            if ((i - coins[j]) >= 0)
            {
                //A quantidade mínima de moedas para obter a soma i é o mínimo entre o valor atual de dp[i] e dp[i - coins[j]] + 1,
                dp[i] = min(dp[i],dp[i-coins[j]]+1);
            }   
        }
    }
    
    return dp[x] >= INT_MAX ? -1 : dp[x];
}


int main()
{
    //n = qtd de moedas e x = soma do valor total
    ll n, x, temp;

    cin >> n >> x;
    
    //Cria o vetor de moedas
    vector<ll> coins(n+10);

    //Recebe as moedas
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    //Passa os valores para a função solve()
    cout << solve(coins, n, x) << endl;
    
    return 0;
}