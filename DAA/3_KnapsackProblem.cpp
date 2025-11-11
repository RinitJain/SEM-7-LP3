#include<iostream>
#include<vector>
using namespace std;

int knapsack(int capacity, int weights[], int values[], int n){
    vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));

    for(int i=1; i<=n; i++){
        //w is a hypothetical capacity - it represents "what if our knapsack had capacity w?"
        for(int w=0; w<=capacity; w++){
            if(weights[i-1] <= w)
                dp[i][w] = max(dp[i-1][w], values[i-1] + dp[i-1][w - weights[i-1]]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    return dp[n][capacity];
}

int main(){
    int n=4;
    int capacity=9;
    int weights[] = {2, 3, 4, 5};
    int values[] = {3, 4, 5, 6};

    int maxValue = knapsack(capacity, weights, values, n);
    cout << "Maximum value in Knapsack = " << maxValue << endl;
    return 0;
}