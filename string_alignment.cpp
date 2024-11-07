
#include <bits/stdc++.h>
using namespace std;


// A global variable for gap 
int gap = 2;
// int cost = 3;

// function to calculate cost:
int cost(char x, char y){
    char vow[] = {'a','e','i','o','u'};
    
    bool x_vow =0;
    bool y_vow = 0;
    
    for (int i =0;i<5;i++){
        if (x == vow[i]){
            x_vow = 1;
            break;
        }
        
    }
    for (int i =0;i<5;i++){
        if(y == vow[i]){
            y_vow = 1;
            break;
        }
    }
    
    if (x_vow == y_vow) return 1;
    else return 3;
}

int str_match(string x,string y){
    int m = x.length();
    int n = y.length();
    
    int dp[m+1][n+1];
    
    // initialising:
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            dp[0][j] = j*gap;
            dp[i][0] = i*gap;
        
        }
        
    }
    // updating values in dp table:
      for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            
        if(x[i-1]==y[j-1])
            dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j]+gap, dp[i][j-1]+gap));
        else
            dp[i][j] = min(dp[i-1][j-1]+cost(x[i],y[j]) ,min(dp[i-1][j]+gap, dp[i][j-1]+gap));
        }
}
// printing dp table
      for(int i=0;i<=m;i++){
          cout<<" | ";
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<" | ";
        }
        cout<<endl;
      }
      cout<<endl;

    return dp[m][n];
}

int main(){
    
    string x = "named";
    string y ="naemse";

    cout<<str_match(x,y);
    return 0;
}
