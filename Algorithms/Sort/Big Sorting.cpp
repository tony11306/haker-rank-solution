// problem source: https://www.hackerrank.com/challenges/big-sorting/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the bigSorting function below.

bool compare(string num1, string num2){ // return true if num1 > num2, else false
    if(num1.length() > num2.length()){
        return true;
    }else if(num1.length() < num2.length()){
        return false;
    }else{
        for(int i = 0; i < num1.length(); ++i){
            if(((int)num1[i]) - 48 > ((int)num2[i]) - 48){
                return true;
            }else if(((int)num1[i]) - 48 < ((int)num2[i]) - 48){
                return false;
            }
        }
    }
    return false;
}

void quickSort(vector<string> &arr, int beginI, int endI){
        if(beginI>=endI){
            return;
        }
        int pivot = beginI;
        string temp;
        for(int i = beginI+1; i<endI+1; i++){
            if(!compare(arr[i], arr[pivot]) && pivot < i){
                temp = arr[pivot+1];
                arr[pivot+1] = arr[i];
                arr[i] = temp;

                temp = arr[pivot];
                arr[pivot] = arr[pivot+1];
                arr[pivot+1] = temp;

                pivot++;
            }
        }
        quickSort(arr,beginI,pivot-1);
        quickSort(arr,pivot+1,endI);

    }

vector<string> bigSorting(vector<string> unsorted) {
    quickSort(unsorted, 0, unsorted.size()-1);
    return unsorted;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
