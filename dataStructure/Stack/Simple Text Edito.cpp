// problem source: https://www.hackerrank.com/challenges/simple-text-editor/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> sta;
string current = "";

void append(string s){
    sta.push_back(current);
    current += s;
}

void del(int k){
    sta.push_back(current);
    string newStr;
    for(int i = 0; i < current.length() - k; ++i){
        newStr += current[i];
    }
    current = newStr;
}

void print(int k){
    printf("%c\n", current[k-1]);
}

void undo(){
    current = sta[sta.size()-1];
    sta.pop_back();
}

int main() {
    int n;
    int operation;
    int k;
    string appendStr;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &operation);
        switch(operation){
            case 1:
                cin >> appendStr;
                append(appendStr);
                break;
            case 2:
                scanf("%d", &k);
                del(k);
                break;
            case 3:
                scanf("%d", &k);
                print(k);
                break;
            default:
                undo();
        }
    }
    return 0;
}
