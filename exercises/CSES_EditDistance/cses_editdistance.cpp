#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 
int solve(string word1, string word2) {
    
    int m = word1.size();
    int n = word2.size();
 
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
 
    for (auto i = 0; i <= m; ++i) {
        dp[i][0] = i;
    }
    for (auto j = 0; j <= n; ++j) {
        dp[0][j] = j;
    }
 
    for (auto i = 1; i <= m; ++i) 
    {
        for (auto j = 1; j <= n; ++j) 
        {
            (word1[i - 1] == word2[j - 1]) ? dp[i][j] = dp[i - 1][j - 1] : dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
    }
 
    return dp[m][n];
}
 
int main() {
    string word1, word2;

    cin >> word1 >> word2;

    cout << solve(word1, word2) << endl;

    return 0;
}