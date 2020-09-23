// problem source: https://www.hackerrank.com/challenges/time-conversion/problem

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
     if(s[8] == 'P'){
        if(s.substr(0, 2) != "12"){
            s.replace(0, 2, to_string(atoi(s.c_str()) + 12));
        }
        s.replace(s.find("P"), 2, "");
         
     }else{
        if(s.substr(0, 2) == "12"){
            s.replace(0, 2, to_string(atoi(s.c_str()) - 12));
        }
        s.replace(s.find("A"), 2, "");

     }
     s = (atoi(s.c_str()) == 0) ? "0" + s : s;
     return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
