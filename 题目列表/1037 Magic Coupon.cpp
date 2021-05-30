#include<bits/stdc++.h>
using namespace std;
int nc[100001];
int np[100001];
int main()
{
    int Nc, Np;
    cin >> Nc;
    for (int i = 0;i < Nc;i++)
        cin >> nc[i];
    cin >> Np;
    for (int i = 0;i < Np;i++)
        cin >> np[i];
    sort(nc, nc + Nc);//从小到大排序
    sort(np, np + Np);
    long long ans = 0;
    int i, j;
    for (i = 0;i < min(Np, Nc) && nc[i] < 0 && np[i] < 0;i++)
        ans += nc[i] * np[i]; 
    //考虑不全面，有可能重复
    //所以要按照对的思路直接写，不要进行转化
    for (j = 1;j <= min(Np, Nc) && nc[Nc - j] > 0 && np[Np - j] > 0;j++)
        ans += nc[Nc - j] * np[Np - j]; 
    cout << ans;
    return 0;
}