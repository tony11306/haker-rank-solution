// problem source: https://www.hackerrank.com/challenges/equal-stacks/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'equalStacks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY h1
 *  2. INTEGER_ARRAY h2
 *  3. INTEGER_ARRAY h3
 */


int getSum(vector<int> arr){
    int arrSize = arr.size();
    int sum = 0;
    for(int i = 0; i < arrSize; ++i){
        sum += arr[i];
    }
    return sum;
}

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    int sumOfH1 = 0, sumOfH2 = 0, sumOfH3 = 0;
    sumOfH1 = getSum(h1);
    sumOfH2 = getSum(h2);
    sumOfH3 = getSum(h3);

    while(sumOfH1 != sumOfH2 || sumOfH2 != sumOfH3){
        if(sumOfH1 > sumOfH2 && sumOfH1 > sumOfH3){
            sumOfH1 -= h1[0];
            h1.erase(h1.begin());
        }else if(sumOfH2 > sumOfH1 && sumOfH2 > sumOfH3){
            sumOfH2 -= h2[0];
            h2.erase(h2.begin());
        }else if(sumOfH3 > sumOfH1 && sumOfH3 > sumOfH2){
            sumOfH3 -= h3[0];
            h3.erase(h3.begin());
        }else if(sumOfH1 != sumOfH2 || sumOfH2 != sumOfH3){
            if(sumOfH1 == sumOfH2){
                sumOfH1 -= h1[0];
                h1.erase(h1.begin());
            }else if(sumOfH2 == sumOfH3){
                sumOfH2 -= h2[0];
                h2.erase(h2.begin());
            }else if(sumOfH1 == sumOfH3){
                sumOfH3 -= h3[0];
                h3.erase(h3.begin());
            }
        }
    }
    return sumOfH1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n1 = stoi(first_multiple_input[0]);

    int n2 = stoi(first_multiple_input[1]);

    int n3 = stoi(first_multiple_input[2]);

    string h1_temp_temp;
    getline(cin, h1_temp_temp);

    vector<string> h1_temp = split(rtrim(h1_temp_temp));

    vector<int> h1(n1);

    for (int i = 0; i < n1; i++) {
        int h1_item = stoi(h1_temp[i]);

        h1[i] = h1_item;
    }

    string h2_temp_temp;
    getline(cin, h2_temp_temp);

    vector<string> h2_temp = split(rtrim(h2_temp_temp));

    vector<int> h2(n2);

    for (int i = 0; i < n2; i++) {
        int h2_item = stoi(h2_temp[i]);

        h2[i] = h2_item;
    }

    string h3_temp_temp;
    getline(cin, h3_temp_temp);

    vector<string> h3_temp = split(rtrim(h3_temp_temp));

    vector<int> h3(n3);

    for (int i = 0; i < n3; i++) {
        int h3_item = stoi(h3_temp[i]);

        h3[i] = h3_item;
    }

    int result = equalStacks(h1, h2, h3);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}