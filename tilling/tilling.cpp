#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    scanf("%d", &n);
    vector<int> h(n, 1);
    m = n;
    while(n != 0){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            h[i]++;
    }
    for(int i = 0; i < m; i++)
        printf("%d ", h[i]);
    printf("%d", 0);
}