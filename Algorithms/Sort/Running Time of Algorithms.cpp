// problem source: https://www.hackerrank.com/challenges/runningtime/problem

#include <bits/stdc++.h>

using namespace std;

int insertionSort(vector<int> &arr){
    int shiftTimes = 0;
    int temp;

    for(int i = 1; i < arr.size(); ++i){
        if(arr[i] < arr[i-1]){
            temp = arr[i];
            for(int j = i; j > 0; --j){
                if(temp >= arr[j-1]){
                    arr[j] = temp;
                    break;
                }
                arr[j] = arr[j-1];
                shiftTimes++;
                if(temp < arr[j-1] && j == 1){
                    arr[j-1] = temp;
                }
            }
        }
    }
    return shiftTimes;
}

int main(){

    int n ;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    cout << insertionSort(arr);
    return 0;
}
