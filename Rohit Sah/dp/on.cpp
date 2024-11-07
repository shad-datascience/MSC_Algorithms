#include<iostream>
#include<algorithm>
using namespace std;

struct Job{
    int start , finish , profit;
};

bool myCmp(Job j1, Job j2){
    return(j1.finish < j2.finish);
}

int nonConflicting(Job arr[] , int i){
    // checking i th job is compatible with previous one or not ;
    for(int j = i-1; j >=0; j--){
        if(arr[j].finish<=arr[i].start){
            // cout<<"================"<<endl;
            // cout<<arr[j].start<<endl;
            // cout<<arr[j].finish<<endl;
            // cout<<arr[j].profit<<endl;
            // cout<<"================"<<endl;
            return j;
        }
    }
    return -1;
}

int profitMax(Job arr[], int n){
    sort(arr,arr+n,myCmp);

    int* opt = new int[n];

    // we defined opt of zero opt(0) = 0; optimum over an empty set;
    opt[0]=arr[0].profit;

    for(int i = 1; i<n; i++){
        int currProfit=arr[i].profit;
        int compatible=nonConflicting(arr,i); //checking is previous job is compatible or not
        if(compatible != -1){
            currProfit+=opt[compatible];
        }
        opt[i]=max(currProfit,opt[i-1]);
    }
    int totalProfit=opt[n-1];
    return totalProfit;
}


int main(){
    Job arr[]={{0,3,2},
                {2,5,4},
                {4,7,4},
                {2,8,7},
                {7,9,2},
                {7,10,1}};
    int n=sizeof(arr)/sizeof(arr[0]);
    // cout<<"Value of n : "<< n<<endl;
    cout<<"Max Profit  DP : "<<profitMax(arr,n)<<endl;
    return 0;
            
}