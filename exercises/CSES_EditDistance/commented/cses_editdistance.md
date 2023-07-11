# Exercício do *CSES*: *Edit Distance*

[**Link do Problema**](https://cses.fi/problemset/task/1639/)

## Código comentado

```
#include <bits/stdc++.h>

using namespace std;

 
int solve(string word1, string word2) {
    
    int m = word1.size();
    int n = word2.size();

    //distância mínima de edição entre os primeiros i caracteres de word1 e os primeiros j caracteres de word2
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
            //Se os caracteres word1[i-1] e word2[j-1] forem iguais, a distância mínima de edição é igual à distância mínima entre os prefixos anteriores
            //Para obter a distância mínima, escolhemos a operação com menor custo entre as seguintes opções: Inserção, Exclusão e Substituição
            (word1[i - 1] == word2[j - 1]) ? dp[i][j] = dp[i - 1][j - 1] : dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
    }
 
    //O valor dp[m][n] (onde m é o tamanho de word1 e n é o tamanho de word2) representa a distância mínima de edição entre as duas palavras.
    return dp[m][n];
}
 
int main() {
    string word1, word2;

    //ler as duas strings
    cin >> word1 >> word2;

    //O uso da programação dinâmica ajuda a evitar a repetição de cálculos desnecessários, pois os resultados intermediários são armazenados na matriz dp.
    cout << solve(word1, word2) << endl;

    return 0;
}
```
