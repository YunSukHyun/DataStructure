#include <bits/stdc++.h>
#define lci list<Customer>::iterator
using namespace std;

struct Customer{
    int id;
    int seat;
    bool operator==(const int& id){
        return (this->id == id);
    }
    void set(int a, int b){
        id   = a;
        seat = b;
    }
};
ostream& operator << (ostream& os, Customer& cst){
    os << cst.id << " " << cst.seat<< '\n';
    return os;
}
int nextSeat(lci vbegin, lci vend, lci vi, int N){
    if(next(vi) == vend)
        return vbegin->seat + N;
    else
        return next(vi)->seat;
}
int rsvSum(int reserve, int N){
    if(reserve > N)
        return reserve - N;
    else
        return reserve;
}

int rsvSeat(int sum, int N){
    if(sum % 2 == 0)
        return rsvSum(sum/2, N);
    else
        return min(rsvSum(sum/2, N), rsvSum(sum/2+1, N));
}

lci rsvItr(lci lsbegin, lci nextitr, int sum, int N){
    if(sum / 2 > N)
        return lsbegin;
    else
        return nextitr;
}
void pushrsv(pair<lci, int>& rsv, list<pair<lci, int>>& list_rsv){
    if(rsv.second < list_rsv.front().second)
        list_rsv.push_front(rsv);
    else
        list_rsv.push_back(rsv);
}

int main(){
    int N, K, id;
    int maxdis, dis;
    int nx, sum;
    pair<lci, int> rsv;
    list<Customer> list_cst;
    list<pair<lci, int> > list_rsv;
    lci fnd, vi;
    scanf("%d %d", &N, &K);
    Customer cst;
    for(int i=0; i<K; i++){
        scanf("%d", &id);
        fnd = find(list_cst.begin(), list_cst.end(), id);
        if(fnd != list_cst.end()){
            list_cst.erase(fnd);
            list_rsv.clear();
        }
        else if(list_cst.size() <= N){
            if(list_cst.empty()){
                rsv = make_pair(list_cst.begin(), 1);
                list_rsv.push_back(rsv);
            }
            else if(list_rsv.empty()){
                maxdis  = 0;
                for(vi = list_cst.begin(); vi != list_cst.end(); vi++){
                    nx  = nextSeat(list_cst.begin(), list_cst.end(), vi, N);
                    dis = nx - vi->seat;
                    if(maxdis <= dis){
                        if(maxdis < dis){
                            maxdis = dis;
                            list_rsv.clear();   
                        }
                        sum = nx + vi->seat;
                        rsv = make_pair( rsvItr(list_cst.begin(),next(vi),sum, N),
                                        rsvSeat(sum, N) );
                        pushrsv(rsv, list_rsv);
                    }
                }
            }
            cst.set(id, list_rsv.front().second);
            list_cst.insert(list_rsv.front().first, cst);
            list_rsv.pop_front();
            cout << cst;
        }
    }
    return 0;
}