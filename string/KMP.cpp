// This algorithm is used to find the pattern in the given word in O(n) time
// we have to find the lps that is longest prefix and suffix that are equal , for the pattern that we wont to search in the word.
// lps[i] denotes the longest prefix and suffix ending at index i.
// so when we perform the search at that time when the string does not match we will not move the i to start instead we will move the i to
// last prfix and suffix ending index that are equal.

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void findlps(string &pat, vector<int>&lps){
    int m = pat.size();
    lps[0] = 0;
    int len = 0;
    int i = 1; 

    while(i < m){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = lps[len - 1];   // may be we have other length prefix and suffix that matches
            }
            else{                      // There is no prefix and suffix that are equal so put it 0
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main(){
    string txt = "ABABABD";
    string pat = "ABABD";
    int n = txt.size();
    int m = pat.size();
    vector<int>lps(m, 0);
    findlps(pat, lps);
    int i = 0; 
    int j = 0;
    while(i < n){
        if(txt[i] == pat[j]){
            i++;
            j++;
        }
        if(j == m){
            cout<<"start index where pattern found is "<<(i - j);
            j = lps[j - 1];
        }
        else if(txt[i] != pat[j]){
            if(j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return 0;
}