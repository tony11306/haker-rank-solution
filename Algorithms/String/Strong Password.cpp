// problem source: https://www.hackerrank.com/challenges/strong-password/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
bool hasNumber(string s){
    for(int i = 0; i < s.length(); ++i){
        if((int)s[i] >= 48 && (int)s[i] <= 57){
            return true;
        }
    }
    return false;

}

bool hasLowerLetter(string s){
    for(int i = 0; i < s.length(); ++i){
        if((int)s[i] >= 97 && (int)s[i] <= 122){
            return true;
        }
    }
    return false;

}

bool hasUpperLetter(string s){
    for(int i = 0; i < s.length(); ++i){
        if((int)s[i] >= 65 && (int)s[i] <= 90){
            return true;
        }
    }
    return false;

}

map<char, int> dict{
        {'!', 1},
        {'@', 1},
        {'#', 1},
        {'$', 1},
        {'%', 1},
        {'^', 1},
        {'&', 1},
        {'*', 1},
        {'(', 1},
        {')', 1},
        {'-', 1},
        {'+', 1}

};



bool hasSpecialChar(string s){
    
    for(int i = 0; i < s.length(); ++i){
        if(dict[s[i]] == 1){
            return true;
        }
    }
    return false;

}

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    int min = 0;
    if(!hasNumber(password))
        min++;
    if(!hasLowerLetter(password))
        min++;
    if(!hasUpperLetter(password))
        min++;
    if(!hasSpecialChar(password))
        min++;
    
    return (n + min >= 6) ? min : min + (6 - min - n);
    

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
