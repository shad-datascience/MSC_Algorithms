#include <iostream>
using namespace std;

// Checking job compatibility 
void compatible_job(int *start, int *finish, int n, int *p) {
    p[0] = 0; //maintaing array p which contains no. jobs are compatible 
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            if (finish[j] <= start[i]) { //checking confilts between the jobs;
                p[i + 1] = j + 1;
                break;
            } else {
                p[i + 1] = 0;
            }
        }
        cout<<i<<"--->"<<p[i]<<" : ";
    }
}

//finding max profit using dp 
int max_profit(int *finish, int *start, int *weight, int n) {
    int *p = new int[n + 1];
    compatible_job(start, finish, n, p);

    //creating dp table to store the results
    int *opt = new int[n + 1];
    opt[0] = 0;  //optimal of 0 is 0 so opt[0]=0;
    cout<<endl<<"Value of  opt 0 : "<<opt[0]<<endl;
    for (int i = 1; i <= n; i++) {
        opt[i] = max(opt[p[i]] + weight[i - 1], opt[i - 1]);
        cout<<endl<<"Value of  opt "<<i<< " : "<<opt[i]<<endl;
    }

    int result = opt[n];
    return result;     
}

int main() {
    int start[] = {0, 2, 4, 2, 7, 7};
    int finish[] = {3, 5, 7, 8, 9, 10};
    int weight[] = {2, 4, 4, 7, 2, 1};
    int n = sizeof(start) / sizeof(start[0]);
    int res=max_profit(finish, start, weight, n);

    cout <<endl<<"DP Solution optimal profit: "<<res<<endl;
    return 0;
}
