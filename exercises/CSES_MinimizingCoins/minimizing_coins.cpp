#include <bits/stdc++.h>

using ll = long long int;
using namespace std;

ll solve(vector<ll> coins, ll n, ll x){
    vector<ll> dp(x+10);

    for (ll i = 1; i <= x; i++)
    {
        dp[i] = INT_MAX;

        for (ll j = 0; j < n; j++)
        {
            if ((i - coins[j]) >= 0)
            {
                dp[i] = min(dp[i],dp[i-coins[j]]+1);
            }   
        }
    }
    
    return dp[x] >= INT_MAX ? -1 : dp[x];
}


int main()
{
    ll n, x, temp;

    cin >> n >> x;
    
    vector<ll> coins(n+10);

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << solve(coins, n, x) << endl;
    
    return 0;
}
