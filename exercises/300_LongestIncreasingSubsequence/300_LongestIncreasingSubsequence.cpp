#include <bits/stdc++.h>
#define ll long long
using namespace std;
using ii = pair<int, int>;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int tam = nums.size(), L[2505], maxValue = INT_MIN;

        for ( auto i = 0; i < tam; ++i ) {
            L[i] = 1;
            for ( auto j = 0; j < i; ++j ) {
                if ( nums[j] < nums[i] && L[j] + 1 > L[i] ) L[i] = L[j] + 1;
            }
        }

        
        for ( auto i = 0; i < tam; ++i ) maxValue = max(maxValue, L[i]);

        return maxValue;
    }
};