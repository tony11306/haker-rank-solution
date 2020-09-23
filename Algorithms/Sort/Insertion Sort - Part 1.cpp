// problem source: https://www.hackerrank.com/challenges/insertionsort1/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the insertionSort1 function below.
void print(vector<int> &arr){
    for(int i = 0; i < arr.size(); ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort1(int n, vector<int> arr) {
    int index;
    int targetValue = arr[n-1];
    for(int i = n-2; i >= 0; --i){
        if(targetValue >= arr[i]){
            index = i;
            break;
        }
    }
    for(int i = n - 2; i > index; --i){
        arr[i+1] = arr[i];
        print(arr);
    }
    arr[index+1] = targetValue;
    print(arr);

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    insertionSort1(n, arr);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
