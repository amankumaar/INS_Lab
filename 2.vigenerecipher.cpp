#include<bits/stdc++.h>
using namespace std;

vector<string> Table;
void build_table(){
    for(int i=0; i<26; i++){
        string s="";
        for(int j=0;j<26;j++){
            s+= char((i+j) % 26 + 97);
        }
        Table.push_back(s);
    }
}

int find_index(char s, char k){
    for(int i = 0; i<26; i++){
        if(Table[int(k-'a')][i] == s)
        return i;
    }
    return -1;
}

void printTable(){
    for(int i = 0; i<26; i++){
        for(int j=0; j<26; j++)
            cout<< Table[i][j]<<" | ";
            cout<<endl;
    }
}

string Encrypt(string S, string key){
    string enc = "";
    for(int i = 0; i<S.length(); i++){
        enc += Table[int(key[(i)%key.length()] - 'a')][int(S[i]-'a')];
    }
    return enc;
}

string Decrypt(string S, string key){
    string dec = "";
    for(int i = 0; i<S.length(); i++){
        dec += char(find_index(S[i], key[(i%key.length())]) + 97);
    }
    return dec;
}
int main(){
    build_table();
    cout<< "Vigenere's table :- "<<endl;
    printTable();
    cout<<endl;
    string input, encoded, decoded, key;
    cout<< "Enter the plain text:- ";
    getline(cin, input);
    cout<<"Enter the key value:- ";
    cin>>key;
    cout<<endl;
    cout<<"****************************"<<endl;
    cout<<endl;
    encoded = Encrypt(input, key);
    cout<< "Encoded Cipher Text:- "<<encoded<< endl;
    decoded = Decrypt(encoded, key);
    cout<< "Decoded plain text:- "<<decoded<<endl;
    return 0;
}