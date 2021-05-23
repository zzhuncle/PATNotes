#include<bits/stdc++.h>
using namespace std;
bool judge(vector<int>& vt)
{
    int n = vt.size();
    for (int i = 0;i < n / 2;i++)
        if (vt[i] != vt[n - 1 - i])
            return false;
    return true;
}
int main()
{
    int N, b;
    cin >> N >> b;
    vector<int> vt;
    while (N) {
        vt.emplace_back(N % b);
        N /= b;
    }
    cout << (judge(vt) ? "Yes" : "No") << endl;
    for (int i = vt.size() - 1;i > 0;i--)
        cout << vt[i] << " ";
    cout << vt[0] << endl;
    return 0;
}
