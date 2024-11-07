#include<iostream>
using namespace std;


// intitialising a Compatibility Array :
static int C[100];
// A function to check the compatibility of jobs:
void compatible(int *S,int *F,int n ){

    C[0] = 0;
    for(int i =0;i<n;i++){
        // for all jobs 1 to n:
        for(int j=i;j>=0;j--){
            // for all jobs starting before i th job:
            if(F[j]<=S[i]){
                // if the finishing time of jth job is  less than the start time of ith job then j is compatiblw with i; 
                C[i+1] = j+1;
                break;
            }
            else
                C[i+1] = 0;
        }
    }
}

// A recursive solution:
int ws_rec(int *F,int *S, int *W,int n){
    
    // updating the compatibilty array:
    compatible(S,F,n);
    
    // if size of the knapsak or the Capacity is 0 return profit 0
    if(n==0 || W ==0)
        return 0;
        
    // else return the max profit in two cases i.e.,including nth job or not including nth job
    return max(ws_rec(F,S,W,C[n])+W[n-1], ws_rec(F,S,W,n-1));
}

// A memoised solution
int ws_mem(int *F,int *S, int *W,int n){
    
    // updating the compatibilty array:
    compatible(S,F,n);
    
    // initiailsing a momeisation table of size n+1
    int M[n+1]={0};
  
    for(int i=1;i<=n;i++)
        if(M[i]==0){
        // the value in Memoised array is the max of (profit of i + profit upto last job compatible[i]) and profit upto i-1th job:
        M[i] = max(ws_mem(F,S,W,C[i])+W[i-1],ws_mem(F,S,W,i-1));
    }
    
    return M[n];
  
}

// A DP solution:
int ws_dp(int *F,int *S, int *W,int n){
    
    // updating the compatibilty array:
    compatible(S,F,n);
    
    // initiailsing a DP table of size n+1
    int T[n+1];
    // initialing the first element with 0
    T[0] = 0;
   
   // for i = 1 to n :
    for(int i=1;i<=n;i++){
        // the value in DP array is the max of (profit of i + profit upto last job compatible[i]) and profit upto i-1th job:
        T[i] = max(T[C[i]]+W[i-1],T[i-1]);
    }
    
    // returning the profit after comparing all n jobs:
    return T[n];
}


int main(){

    int S[]={3,1,6,2};
    int F[] = {10,2,19,100};
    int W[] = {20,50,100,200};
    
    // Calculating the no. of jobs:
    int n = sizeof(S)/sizeof(S[0]);
    
    cout<<"Recursive Solution :";
    cout<<ws_rec(F,S,W,n);
    cout<<endl;
    cout<<"Mem Solution :";
    cout<<ws_mem(F,S,W,n);
    cout<<endl;
    cout<<"DP Solution :";
    cout<<ws_dp(F,S,W,n);
    return 0;
}