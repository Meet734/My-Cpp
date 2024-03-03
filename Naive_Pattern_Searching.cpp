//Naive pattern searching algorithm is a simple algorithm that is used to search for a pattern in a text.
//It is a simple algorithm that checks for all character of the main string to the pattern.
//The time complexity of the Naive pattern searching algorithm is O(m*(n-m+1)) where m is the length of the pattern and n is the length of the main string.
//The space complexity of the Naive pattern searching algorithm is O(1).
#include<bits/stdc++.h>
using namespace std;

void search(string txt,string pat){
    int i,j;
    int n = txt.length();
    int m = pat.length();

    for(i=0;i<n-m;i++){
        for(j=0;j<m;j++){
            if(txt[i+j]!=pat[j]){
                break;
            }
        }
        if(j==m){
            cout<<"Pattern found at index: "<<i<<endl;
        }
    }
}
int main(void){
    string txt,pat;
    cout<<"Enter string txt: ";
    getline(cin, txt);

    cout<<"Enter string pat: ";
    getline(cin, pat);

    search(txt,pat);

    return 0;
}
