// problem source: https://www.hackerrank.com/challenges/reduced-string/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {
    string result = "";
    for(int i = 0; i < s.length(); ++i){
        if(i+1 < s.length() && s[i] == s[i+1]){
            i++;
            continue;
        }
        result += s[i];
    }
    if(result != s){
        result = superReducedString(result);
    }
    return result.length() == 0 ? "Empty String" : result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
