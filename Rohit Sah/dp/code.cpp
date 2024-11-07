#include<iostream>
using namespace std;

void compatible_job(int *start , int *finish , int n , int *p){
    p[0]=0;
    for(int i = 0;  i<n; i++){
        for (int j=i; j>=0; j--){
            if(finish[j]<=start[i]){
                p[i+1]=j+1;
                break;
            }else{
                p[i+1]=0;
            }
            cout<<i<<" ---> "<<p[i];
        }
    }
}

int max_profit(int *finish, int *start, int *weight, int n){
    int *p=new int[n+1];
    compatible_job(start,finish,n,p);

    int *opt=new int[n+1];
    opt[0] = 0;
    for (int i = 1; i <=n; i++)
    {
        opt[i]=max(opt[p[i]]+weight[i-1],opt[i-1]);
    }
    int result = opt[n];
    return result;
}

void compatible_job(int * start , int* finish , int n , int *p){
    p[0]=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >=0; j++)
        {
            if(finish[j]<=start[i]){
                p[i+1]=j+1;
                break;
            }else{
                p[i+1]=0;
            }
            
        }
        
    }
    
}

void compatible_job(int * start , int* finish , int n , int* p){
    p[0]=0;
    for (int i = 0; i <n ; i++)
    {
        for (int j = i; j>=0; j--)
        {
            if(finish[j]<=start[i]){
                p[i+1]=j+1;
            }else{
                p[i+1]=0;
            }
        }
        
    }
     
}

int max_profit(int * start , int* finish , int * weight , int n){
   int * p = new int[n+1];
   compatible_job(start,finish,n,p);

   int *opt = new int[n+1];
   opt[0]=0;
   for (int i = 1; i <=n; i++)
   {
        opt[i]=max(opt[p[i]]+weight[i-1],opt[i-1]);
   }
   int result=opt[n];
   return result;
}

int max_profit(int *start,int *finish, int *weight, int n){
    int *p = new int[n+1];
    compatible_job(start,finish,n,p);

    int *opt = new int[n+1];
    opt[0]=0;

    for (int i = 1; i <= n; i++)
    {
        opt[i]=max(opt[p[i]]+weight[i-1],opt[i-1]);

    }
    int res= opt[n];

    return res;
    
}

int max_profit(int* start, int* finish , int* weight , int n){
    int * p = new int[n+1];

    compatible_job(start,finish,n,p);

    int *opt= new int[n +1];
    opt[0]=0;
    for (int i = 1; i <= n; i++)
    {
        opt[i]=max(opt[p[i]]+weight[i],opt[i-1]);
    }
    int res=opt[n];

    return res;    
}

void compatible_job(int *start , int *finish , int n , int *p){
    p[0]=0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i;j >= 0; j--)
        {
            if (finish[j]<=start[i])
            {
                p[i+1]=j+1;
                break;
            }else{
                p[i+1]=0;
            }
            
        }
        
    }

}

int max_profit(int *start , int * finish, int * weight  , int n){
    int *p =new int[n+1];
    compatible_job(start, finish,n , p );
    int * opt = new int[n+1];

    opt[0]=0;

    for (int i = 1; i <=n; i++)
    {
        opt[i]=max(opt[p[i]]+weight[i-1],opt[i-1]);

    }
    int res =opt[n];
    
}
