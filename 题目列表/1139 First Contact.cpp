//水题 但是值得一做，题目比较新颖，处理比较复杂
#include<bits/stdc++.h>
using namespace std;
class node//用于记录结果
{
public:
    int first;
    int second;
    node (int x, int y)
    {
        first = x;
        second = y;
    }
};
bool cmp(node x, node y)
{
    return (x.first < y.first) || (x.first == y.first && x.second < y.second);
}
unordered_map<int, bool> arr;//⽤v标记所有⼈的同性朋友（邻接表表示）
vector<int> v[10000];    //⽤数组arr标记两个⼈是否是朋友（邻接矩阵表示）
int main()
{
    int n, m, k;
    cin >> n >> m;
    for (int i = 0;i < m;i++) {
        string a, b;
        cin >> a >> b;
        int ia = abs(stoi(a)), ib = abs(stoi(b));
        if (a.length() == b.length()) {
            v[ia].push_back(ib);
            v[ib].push_back(ia);
        }
        arr[ia * 10000 + ib] = arr[ib * 10000 + ia] = true;
    }
    cin >> k;
    //对于⼀对想要在⼀起的A和B，他们需要先找A的所有同性朋友C，再找B的所有同性朋友D，当C和D两
    //⼈是朋友的时候则可以输出C和D。
    for (int i = 0;i < k;i++) {
        vector<node> ans;
        int c, d;
        cin >> c >> d;
        c = abs(c), d = abs(d);
        for (int j = 0;j < v[c].size();j++) {
            for (int k = 0;k < v[d].size();k++) {
                int cj = v[c][j], dk = v[d][k];
                if (cj == d || dk == c)//同性朋友
                    continue;
                if (arr[cj * 10000 + dk] == true)
                    ans.push_back(node(cj, dk));
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        cout << ans.size() << endl;
        for (int j = 0;j < ans.size();j++)//注意需要输出四位数字，不足四位需要补齐
            printf("%04d %04d\n", ans[j].first, ans[j].second);
    }
    return 0;
}