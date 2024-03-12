//Luhn algorithm
#include<iostream>
#include<algorithm>
using namespace std;

bool check(string cardNumber){
    if(cardNumber.length() != 11){
        return false;
    }

    reverse(cardNumber.begin(), cardNumber.end());

    int check_digit = cardNumber[0] - '0';
    int sum = 0;

    for(int i=1;i<cardNumber.length();i++){
        int temp = cardNumber[i] - '0';
        if(i & 1){
            temp *= 2;
        }
        while(temp){
            sum += temp%10;
            temp /= 10;
        }
    }
    // cout<<sum<<endl;

    int derived_check_digit = (10 - (sum % 10) % 10);
    
    return (derived_check_digit == check_digit);
}
int main(void){
    string s;
    cout<<"Enter number: ";
    cin>>s;

    bool isValid = check(s);
    
    if(isValid){
        cout<<"Valid\n";
    }
    else{
        cout<<"Invalid\n";
    }
}