# Exercício *300* do *LeetCode*: *Longest Increasing Subsequence*

[**Link do Problema**](https://leetcode.com/problems/longest-increasing-subsequence/)

## Código comentado

```
#include <bits/stdc++.h>
#define ll long long
using namespace std;
using ii = pair<int, int>;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
            Temos o tamanho do vetor dado (com os números em questão) e
            o vetor L para o armazenamento da maior subsequência até o devido
            número (memoização).
        */
        int tam = nums.size(), L[2505], maxValue = INT_MIN;

        for ( auto i = 0; i < tam; ++i ) {
            /*
                Passando por cada elemento do vetor, iniciamos a contagem do tamanho da
                subsequência máxima a partir de 1 (que é o tamanho mínimo da subsequência)
                e então passamos, em outro laço, por todos os elementos anteriores a cada
                um destes, incrementando assim o tamanho da subsequência e posteriormente 
                salvando no vetor L (de memoização).
            */
            L[i] = 1;
            for ( auto j = 0; j < i; ++j ) {
                if ( nums[j] < nums[i] && L[j] + 1 > L[i] ) L[i] = L[j] + 1;
            }
        }

        // Por fim, recolhemos o valor da maior subsequencia e o retornamos para o usuario
        for ( auto i = 0; i < tam; ++i ) maxValue = max(maxValue, L[i]);

        return maxValue;
    }
};
```
