#include<bits/stdc++.h>
using namespace std;
double k[1001] = { 0 };
int main()
{
    int n1, n2, nk;
    double ank;
    cin >> n1;
    for (int i = 0;i < n1;i++) {
        cin >> nk >> ank;
        k[nk] += ank;
    }
    cin >> n2;
    for (int i = 0;i < n2;i++) {
        cin >> nk >> ank;
        k[nk] += ank;
    }
    int cnt = 0;
    for (int i = 0;i <= 1000;i++)
        if (fabs(k[i]) > 1e-6)
            cnt++;
    cout << cnt;
    for (int i = 1000;i >= 0;i--)
        if (fabs(k[i]) > 1e-6)
            printf(" %d %.1lf", i, k[i]);
    printf("\n");
    return 0;
}
