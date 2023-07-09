#include <iostream>
#include <vector>

using ll = long long;

using namespace std;
long long solve(vector<ll> coins, ll n, ll x){
    if (n == 0)
    {
        return 0;
    }
    
    vector<ll> dp(n + 1);

    dp[0] = 0;

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < x; j++)
        {
            if (coins[j] <= i)
            {
                ll count = dp[i - coins[j]];
                if (count != INT_MAX && count + 1 < dp[i])
                {
                    dp[i] = count + 1;
                }
                
            }
            
        }
        
    }

    return (dp[n] == INT_MAX) ? -1 : dp[n]; 
    
}


int main()
{
    //n=qtd de moedas, x=soma total
    ll n, x;

    cin >> n >> x;
    vector<ll> coins(n+1);

    for (ll i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << solve(coins, x, n) << endl;
    
    return 0;
}
