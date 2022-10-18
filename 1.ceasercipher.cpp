#include<bits/stdc++.h>
using namespace std;

string encode(string pt, int key){
    string result = "";
    for(int i=0; i<pt.length(); i++){
        if(isupper(pt[i]))
        result += char(int(pt[i] + key - 65) % 256 + 65); 
        else
        result += char(int(pt[i] + key -97) % 256 + 97);
    }
    return result;
}

string decode(string ct, int key){
    // Cipher Text = ct
    string result = "";
    for(int i=0;i<ct.length();i++){
        if(isupper(ct[i]))
        result += char(int(ct[i] - key - 65) % 256 + 65);
        else
        result += char(int(ct[i] - key - 97) % 256 + 97);
    }
    return result;
}

int main(){
    // PlainText = pt
    string pt, encoded, decoded;
    int key;
    cout<<"Input the Plain Text:- ";
    getline(cin,pt);
    cout<<"Input the Key Value:- ";
    cin>>key;
    encoded = encode(pt,key);
    cout<<endl;
    cout<<"*******************************"<<endl;
    cout<<endl;
    cout<<"Encoded Cipher Text:- "<< encoded<<endl;
    decoded = decode(encoded,key);
    cout<<"Decode Plain Text:- "<<decoded<<endl;
    return 0;
}