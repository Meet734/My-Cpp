//Longest common subsequence using dynamic programming
#include<iostream>
using namespace std;

int main(void){
    cout<<"Enter string1: ";
    string s;
    getline(cin, s);

    cout<<"Enter string2: ";
    string t;
    getline(cin, t);

    int l1 = s.length();
    int l2 = t.length();
    int dp[l1+1][l2+1];

    for(int i=0;i<=l1;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=l2;i++){
        dp[0][i] = 0;
    }

    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    /*
    for(int i=0;i<=l1;i++){
        for(int j=0;j<=l2;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    */

    cout<<"\tLength of longest possible subsequence: "<<dp[l1][l2]<<endl;

    return 0;
}