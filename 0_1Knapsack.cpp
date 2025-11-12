#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int> &val, vector<int> &wt) 
    {
        // code here
        int n= val.size();
        
        //recursion
        return helper(val, wt, n, W);
        
        //memoisation
        // vector<vector<int>>dp(n+1, vector<int>(W+1, -1));
        // return helper(val, wt, n, W, dp);
        
    }
    
    // Recursion
    
    int helper(vector<int>& val, vector<int>& wt, int n, int W)
    {
        //Base Case
        if(n==0 || W==0)            return 0;
        if(n==1 && W< wt[n-1])      return 0;
        if(n==1 && W>= wt[n-1])     return val[n-1];
        
        //reccurance
        int profit1=0;
        if(W<wt[n-1])
        {
            profit1 = helper(val, wt, n-1, W);
        }
        int profit2 = 0;
        if(W>=wt[n-1])
        {
            int pick = val[n-1] +  helper(val, wt, n-1, W-wt[n-1]);
            int not_pick = 0 + helper(val, wt, n-1, W);
            profit2 = max(pick, not_pick);
        }
        
        return max(profit1, profit2);
    }
    
    //Memoisation
    
    // int helper(vector<int>& val, vector<int>& wt, int n, int W, vector<vector<int>>& dp)
    // {
    //     //Base Case
    //     if(n==0 || W==0)            return 0;
    //     if(n==1 && W< wt[n-1])      return 0;
    //     if(n==1 && W>= wt[n-1])     return val[n-1];
        
    //     if(dp[n][W]!=-1)   return dp[n][W];
        
    //     //reccurance
    //     int profit1=0;
    //     if(W<wt[n-1])
    //     {
    //         profit1 = helper(val, wt, n-1, W, dp);
    //     }
    //     int profit2 = 0;
    //     if(W>=wt[n-1])
    //     {
    //         int pick = val[n-1] +  helper(val, wt, n-1, W-wt[n-1], dp);
    //         int not_pick = 0 + helper(val, wt, n-1, W, dp);
    //         profit2 = max(pick, not_pick);
    //     }
        
    //     return dp[n][W]= max(profit1, profit2);
    // }

int main() 
{
	int W = 50; // Knapsack capacity
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};

    int maxProfit = knapsack(W, val, wt);
    
    cout<<maxProfit<<endl;
}
