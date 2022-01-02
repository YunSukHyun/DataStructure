#include <bits/stdc++.h>
using namespace std;
struct Node{
    string name, par;
    vector<string> sub;
    int dpt = 0, sub_num = 0;
    void setPar(string s1, string s2){
        name = s1;
        par  = s2;
    }
    void setSub(string s1, string s2){
        name = s1;
        sub.push_back(s2);
    }
    void setRoot(string s){
        name = s;
        par  = "";
    }
    void addSub(string s){
        sub.push_back(s);
    }
};
vector<Node> nv;
set<string> nodeName;
string rn;
bool flag = false;

bool cmp(const Node& a, const Node& b){
    if(a.sub_num > b.sub_num)
        return true;
    else if(a.sub_num == b.sub_num){
        if(a.dpt < b.dpt)
            return true;
        else if(a.dpt == b.dpt){
            if(a.name < b.name)
                return true;
        }   
    }
    return false;
}
int myFind(string s){
    for(int i = 0; i < nv.size(); i++){
        if(s == nv[i].name)
            return i;
    }
    return -1;
}

void DFS(Node& n, int& d){
    if(flag == true)
        return;
    if(n.par == "")
        flag == true;
    n.sub_num++; d++;
    for(int i = 0; i < nv.size(); i++){
        if(n.par == nv[i].name)
            DFS(nv[i], d);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, idx, depth;
    string s1, s2;
    Node nd, rd;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> s1 >> s2;
        nd.setPar(s1, s2);
        nv.push_back(nd);
        nodeName.insert(s1);
    }
    for(int i = 0; i < nv.size(); i++){
        idx = myFind(nv[i].par);
        if(nodeName.count(nv[i].par) == 0){
            rn = nv[i].par;
            nodeName.insert(rn);
        }
        if(idx != -1)
            nv[idx].addSub(nv[i].name);
    }
    rd.setRoot(rn);
    nv.push_back(rd);
    for(int i = 0; i < nv.size()-1; i++){
        if(nv[i].par == rn)
            nv[nv.size()-1].addSub(nv[i].name);
    }
    for(int i = 0; i < nv.size(); i++){
        depth = 0;
        DFS(nv[i], depth);
        nv[i].dpt = depth;
    }
    sort(nv.begin(), nv.end(), cmp);
    for(int i = 0; i < nv.size(); i++)
        cout << nv[i].name << '\n';
}

