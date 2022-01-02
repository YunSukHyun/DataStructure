#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n, k;
    string act, n1, n2;
    cin >> n >> k;
    list<int> da(n/2);
    list<int> db(n/2);
    list<int> rst(n);
    for(int i = 0; i < k; i++){
        if(i == 0){
            iota(da.begin(), da.end(), 1);
            iota(db.begin(), db.end(), n/2+1);
            iota(rst.begin(), rst.end(), 1);
        }
        auto ita = da.begin();
        auto itb = db.begin();
        auto itr = rst.begin();
        cin >> act;
        if(act == "Shuffle"){
            rst.clear();
            for(int j = 0; j < n/2; j++){
                rst.push_back(*ita);
                rst.push_back(*itb);
                ita++; itb++;
            }
        }
        else if(act == "Cut"){
            cin >> n1 >> n2;
            auto itr2 = rst.begin();
            advance(itr,  stoi(n1)-1);
            advance(itr2, stoi(n2));
            rst.splice(rst.end(), rst, itr, itr2);
        }
        da.clear();
        db.clear();
        if(i != k-1){
            ita = da.begin();
            itb = db.begin();
            itr = rst.begin();
            advance(itr, n/2);
            da.assign(rst.begin(), itr);
            db.assign(itr, rst.end());
        }
    }
    auto itr = rst.begin();
    cout << *itr << ' ';
    advance(itr, n/2-1);
    cout << *itr << ' ';
    itr = rst.end(); itr--;
    cout << *itr;
    return 0;
}