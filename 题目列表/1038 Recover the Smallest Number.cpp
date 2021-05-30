#include<bits/stdc++.h>
using namespace std;
bool cmp(string a, string b)
{
    return a + b < b + a;
}
int main()
{
    int n;
    cin >> n;
    vector<string> vt(n, "");
    for (int i = 0;i < n;i++)
        cin >> vt[i];
    sort(vt.begin(), vt.end(), cmp);
    string ans = "";
    for (int i = 0;i < vt.size();i++)
        ans += vt[i];
    int i;
    for (i = 0;i < ans.length();i++)
        if (ans[i] != '0')
            break;
    ans = ans.substr(i);
    if (ans == "")//注意特判
        ans = "0";
    cout << ans << endl;
    return 0;
}
