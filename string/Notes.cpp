// stringstream ss(sentence) -- this is used to iterate in the sentence.
// we will use the getline(stringstreamName, varibale, delimeter)
// getline(ss, str, ' ') -- str is the variable in which we will store the words.
// we can also use while(ss > str){} it will iterate till then there is word in the string variable ss.



#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    string sentence = "Do  the     hard    work to get the hard things Do";
    stringstream ss(sentence);
    string str = "";

    while(ss >> str){
        cout<<str<<" ";
    }
    return 0;
}