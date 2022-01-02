#include <bits/stdc++.h>
using namespace std;
typedef pair<char, int> pci;
int n, cnt;
set<char> chk;
struct Connection{
    char head;
    vector<char> cn;
};
struct Way{
    char loc;
    vector<int> p;
    Way(char a, int b){
        loc = a;
        p.push_back(b);
    }
};
bool cmp(Way& a, Way& b){
    sort(a.p.begin(), a.p.end(), greater<int>());
    sort(b.p.begin(), b.p.end(), greater<int>());
    if(a.p[0] == b.p[0])
        return a.loc < b.loc;
    return a.p[0] < b.p[0];
}
queue<pci> q;
vector<Connection> cv;
vector<Way> wv;
void myPushBack(char c, int num){
    for(int i = 0; i < wv.size(); i++){
        if(wv[i].loc == c){
            wv[i].p.push_back(num);
            return;
        }
    }
    wv.push_back(Way(c, num));
}
void BFS(char c){
    int sz, idx, tmp;
    char vst;
    q.push({c, 0});
    myPushBack(c, 0);
    chk.insert(c);
    while(!q.empty()){
        char head    = q.front().first;
        int  howLong = q.front().second;
        q.pop();
        for(int i = 0; i < n; i++){
            if(cv[i].head == head){
                sz = cv[i].cn.size();
                idx = i;
                break;
            }
        }
        for(int i = 0; i < sz; i++){
            vst = cv[idx].cn[i];
            if(howLong == 0)
                tmp = howLong + 1;
            else if(howLong >= 1)
                tmp = howLong + 3;
            if(!chk.count(vst)){
                q.push({vst, tmp});
                chk.insert(vst);
                myPushBack(vst, tmp);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    char vertex, p1, p2, p3;
    char cHead, cConn;
    cin >> n;
    cin >> p1 >> p2 >> p3;
    for(int i = 0; i < n; i++){
        Connection con;
        cin >> vertex;
        con.head = vertex;
        while(1){
            cin >> vertex;
            if(vertex == '$') break;
            con.cn.push_back(vertex);
        }
        cv.push_back(con);
    }
    BFS(p1);
    chk.clear();
    BFS(p2);
    chk.clear();
    BFS(p3);
    sort(wv.begin(), wv.end(), cmp);\
    int finalCnt=0;
    for(int i = 0; i < wv.size(); i++){
        for(int j = 0; j < 3; j++)
            if(wv[i].p[j] == 0) finalCnt++;
    }
    if(finalCnt > 3)
        cout << '@' << '\n' << -1;

    else
        cout << wv[0].loc << '\n' << wv[0].p[0];
}