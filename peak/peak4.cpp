#include <bits/stdc++.h>
using namespace std;
typedef pair<int, char> pic;
struct Interval{
    int bg, ed, num, itv;
    void set(int b, int c){
        ed = b; num = c;
        itv = abs(bg - ed);
    }
};
struct cmp1{
	bool operator()(pic& a, pic& b){
		if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first > b.first;
	}
};
struct cmp2{
    bool operator()(Interval& a, Interval& b){
        if(a.num == b.num){
            if(a.itv == b.itv)
                return a.ed < b.ed;
            return a.itv < b.itv;
        }
        return a.num < b.num;
    }
};
priority_queue<pic, vector<pic>, cmp1> pqc;
priority_queue<Interval, vector<Interval>, cmp2> pqi;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, b, e, cnt = 1;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> b >> e;
        pqc.push({b, 'b'});
        pqc.push({e, 'e'});
    }
    Interval interval;
    while(!pqc.empty()){
        if(pqc.top().second == 'b'){
            cnt++;
            interval.bg = pqc.top().first;
        }
        else{
            cnt--;
            interval.set(pqc.top().first, cnt);
            pqi.push(interval);
        }
        pqc.pop();
    }
    cout << pqi.top().bg << ' ' << pqi.top().ed;
}