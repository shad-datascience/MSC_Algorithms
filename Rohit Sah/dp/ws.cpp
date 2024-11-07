#include <iostream>
#include <algorithm>
using namespace std;

//definig the job structure
struct Job {
    int start, finish, weight;
};

//making comparator for sorting jobs according to its finish time 
bool jobComparator(Job s1, Job s2) {
    return (s1.finish < s2.finish);
}

//checking for compatible job non conflicting jobs
void compatible_job(Job jobs[], int n, int *p) {
    p[0] = 0; //maintaing array p which contains no. jobs are compatible
    int lastCompatible = 0;
    for (int i = 1; i < n; i++) {
        
        while ((lastCompatible < i) && (jobs[lastCompatible].finish <= jobs[i].start)) {
            lastCompatible++;
        }
        cout<<i<<" --> "<<lastCompatible<<" : ";
        p[i] = lastCompatible;
    }
}

//finding max profit using dp 
int max_profit(Job jobs[], int n) {
    int *p = new int[n];
    compatible_job(jobs, n, p);

    //creating dp table to store the results
    int *opt = new int[n + 1];
    opt[0] = 0;

    cout<<endl<<"Value of  opt 0 : "<<opt[0]<<endl;
    for (int i = 1; i <= n; i++) {
        opt[i] = max(opt[p[i - 1]] + jobs[i - 1].weight, opt[i - 1]);
        cout<<endl<<"Value of  opt "<<i<< " : "<<opt[i]<<endl;
    }

    int result = opt[n];
    delete[] opt;
    delete[] p;
    return result;
}

int main() {
    Job jobs[] = {{0, 3, 2}, {2, 5, 4}, {4, 7, 4}, {2, 8, 7}, {7, 9, 2}, {7, 10, 1}};
    int n = sizeof(jobs) / sizeof(jobs[0]);
    // int n = 6;

    // Sort jobs according to finish time
    //jobs: This is the pointer to the first element in the array that you want to sort.
    // jobs + n: This is the pointer to the element just past the last element in the array. The range
    sort(jobs, jobs + n, jobComparator);
    int res=max_profit(jobs, n);

    cout << "DP Solution: "<<res;
    return 0;
}
