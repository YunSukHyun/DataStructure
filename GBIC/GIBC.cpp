#include <bits/stdc++.h>
using namespace std;
map<set<int>, vector<int> > genetic;
set<int> setKey;
int g;
void report(){
    while(1){
        cin >> g;
        if(g < 0){
            for(int i = 0; i < genetic[setKey].size(); i++){
                if(genetic[setKey][i] == g){
                    setKey.clear();
                    break;
                }
            }
            genetic[setKey].push_back(g);
            setKey.clear();
            break;
        }
        else
            setKey.insert(g);
    }
}
void query(){
    while(1){
        cin >> g;
        if(g == 0){
            if(genetic.count(setKey) == 1){
                sort(genetic[setKey].begin(), genetic[setKey].end(), greater<int>());
                for(int i = 0; i < genetic[setKey].size(); i++){
                    cout << genetic[setKey][i] << ' ';
                }
            }
            else{
                cout << "None";
            }
            cout << '\n';
            setKey.clear();
            break;
        }
        else{
            setKey.insert(g);
        }
    }
}
int main(){
    char opt;
    while(1){
        cin >> opt;
        if(opt == '$') break;
        switch(opt){
            case 'R':
                report();
                break;
            case 'Q':
                query();
                break;
        }
    }
}