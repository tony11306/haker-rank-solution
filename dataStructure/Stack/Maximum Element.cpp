// problem source: https://www.hackerrank.com/challenges/maximum-element/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n = 0;
    int choice;
    int element;
    int staSize;
    int max = 0;
    int temp;
    vector<int> sta;
    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i){
        scanf("%d", &choice);
        if(choice == 1){
            scanf("%d", &element);
            sta.push_back(element);
            if(element > max){
                max = element;
            }

        }else if(choice == 2){
            temp = sta[sta.size()-1];
            sta.pop_back();
            if(temp == max){
                max = 0;
                for(int j = 0; j < sta.size(); ++j){
                    if(sta[j] > max){
                        max = sta[j];
                    }
                }
            }
            
        }else{
                printf("%d\n", max);
        }
    } 
    return 0;
}
