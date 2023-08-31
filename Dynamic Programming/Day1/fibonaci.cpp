#include<iostream>
#include<vector>
using namespace std;

int fib(int n,vector<int>&dp){
    //base case
    if( n <= 1){
        return n;
    }

    // step 3 
    if(dp[n] != -1){
        return dp[n];
    }

    //step 2 store the returning value then return 

    //memoization
    dp[n] = fib(n - 2,dp) + fib(n - 1,dp);
    return dp[n];
}
int main(){



    int n ;
    cout << "enter a number n" << endl;
    cin >> n;

    // // method 1 top Down approach recursion + memoization 
    
    // // step 1 create a 1D array of size n+1
    // vector<int> dp(n + 1);
    // //initialize it with -1
    // for (int i = 0; i <= n; i++){
    //     dp[i] = -1;
    // }


    // //function call
    // cout << fib(n, dp) << endl;


    //method 2

    // bottom up approach called Tabulation

    // //step 1 create a dp array
    // vector<int> dp(n + 1);
    // // step 2 analysis base case  

    // dp[1] = 1;
    // dp[0] = 0;

    // //step 3 
    // for (int i = 2; i <= n; i++){
    //     dp[i] = dp[i - 1] + dp[i - 2];
    // }
    // cout << dp[n] << endl;


    // space optimization

    int prev1 = 1;
    int prev2 = 0;

    if(n == 0){
        cout << 0 << endl;
    }

    for (int i = 2; i<=n; i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    cout << prev1 << endl;

    return 0;
}