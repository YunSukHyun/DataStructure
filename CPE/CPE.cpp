#include <bits/stdc++.h>
using namespace std;
vector<vector<string> > kor;
vector<string> v;
string Only_Hangul(string p ){
    string Ohan  ;
    int nn = p.size();
    for(int i=0; i<nn; i++) {
         if((p[i] & 0x80) != 0) {
             Ohan.push_back(p[i]);
         }
    } // end of for(i)
    return ( Ohan ) ;
} // end of ONly_Hangul( )

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    string s, rst;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        // while(s != "$"){
        //     rst += s;
        //     cin >> s;
        // }
        getline(cin, rst);
        rst = Only_Hangul(rst);
        v.push_back(rst);
        rst.clear();
    }
    
    // cout << rst.size() << '\n';
    // cout << rst.substr(2, 2);
    for(int i = 0; i < rst.size(); i++){
        
    }
}