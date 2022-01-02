#include <bits/stdc++.h>

#define f first
#define s second
using namespace std;

map<string, vector<string> > input;
vector<string> ans;
set<string> func;
bool flag = false;

void DFS(string upper){
    for(int i = 0; i < input[upper].size(); i++){
        if(flag) return;
        if(input[upper][i] == "$"){
            func.erase(upper);
            return;
        }
        else if(input[upper][i] >= "A" && input[upper][i] <= "Z"){
            if(func.find(input[upper][i]) != func.end()){
                flag = true;
                return;
            }
            func.insert(input[upper][i]);
            DFS(input[upper][i]);
        }
        else
            ans.push_back(upper+"-"+input[upper][i]);
    }
}
int main(){
    int n, k1, k2;
    scanf("%d %d %d", &n, &k1, &k2);
    string s;
    string e="";
    for(int i = 0; i < n; i++){
        vector<string> sv;
        cin >> s;
        while(1){
            cin >> e;
            sv.push_back(e);
            if(e == "$") break;
        }
        input[s] = sv;
    }
    DFS("M");
    if(flag)
        printf("DEADLOCK");
    else{
        if(k1 <= ans.size())
            cout << ans[k1-1] << '\n';
        else
            cout << "NONE" << '\n';
        if(k2 <= ans.size())
            cout << ans[k2-1];
        else
            cout << "NONE";
    }
    // for(auto c : input){
    //     cout << c.f << ": ";
    //     for(auto c2 : c.s){
    //         cout << c2 << ' ';
    //     }
    //     cout << endl;;
    // }
}