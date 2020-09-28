// problem source: https://www.hackerrank.com/challenges/lilys-homework/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the lilysHomework function below.


int lilysHomework(vector<int> arr) {
    vector<int> sortedArr;
    vector<int> arrCopy;
    map<int, int> arrMap;
    map<int, int> arrMap2;
    int ascSwapTimes = 0;
    int desSwapTimes = 0;
    sortedArr.assign(arr.begin(), arr.end());
    arrCopy.assign(arr.begin(), arr.end());
    sort(sortedArr.begin(), sortedArr.end());
    for(int i = 0; i < arr.size(); ++i){
        arrMap[arr[i]] = i;
        arrMap2[arr[i]] = i;
    }
    for(int i = 0; i < arr.size(); ++i){
        if(arr[i] != sortedArr[i]){
            arr[arrMap[sortedArr[i]]] = arr[i];
            arrMap[arr[i]] = arrMap[sortedArr[i]];
            ascSwapTimes++;
        }
    }
    reverse(sortedArr.begin(), sortedArr.end());
    for(int i = 0; i < arr.size(); ++i){
        if(arrCopy[i] != sortedArr[i]){
            arrCopy[arrMap2[sortedArr[i]]] = arrCopy[i];
            arrMap2[arrCopy[i]] = arrMap2[sortedArr[i]];
            desSwapTimes++;
        }
    }

    return (ascSwapTimes <= desSwapTimes) ? ascSwapTimes : desSwapTimes;

}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

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

    int result = lilysHomework(arr);

    fout << result << "\n";

    fout.close();

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
