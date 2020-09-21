// problem source: https://www.hackerrank.com/challenges/balanced-brackets/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    if(s.length() %2 != 0){
        return "NO";
    }
    map<char, char> charMap;
    charMap['{'] = '}';
    charMap['['] = ']';
    charMap['('] = ')';
    stack<char> sta;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '{' || s[i] == '[' || s[i] == '('){
            sta.push(s[i]);
        }else{
            if(sta.size() == 0){
                return "NO";
            }
            if(charMap[sta.top()] != s[i]){
                return "NO";
            }
            sta.pop();
        }
    }
    return sta.empty() ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
