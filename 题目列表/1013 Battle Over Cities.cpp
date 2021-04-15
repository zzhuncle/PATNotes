//(浙大) https://pintia.cn/problem-sets/994805342720868352/problems/994805500414115840
//并查集
#include<bits/stdc++.h>
#define MAXN 1001
using namespace std;
int height[MAXN];
int father[MAXN];
vector<pair<int, int>> G;   //邻接表
void Init(int n)
{
    for (int i = 1;i <= n;i++) {
        height[i] = 1;
        father[i] = i;
    }
}
int Find(int x)
{
    if (x != father[x])
        x = Find(father[x]);
    return father[x];
}
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x != y) {
        if (height[x] < height[y]) 
            father[x] = y;
        else if (height[x] > height[y])
            father[y] = x;
        else {
            height[x]++;
            father[y] = x;
        }
    }
}
int main()
{
    int n, m ,k;//总城市数目 现存铁路数 被敌人占领城市数
    while (cin >> n >> m >> k) {
        for (int i = 0;i < m;i++) {
            int from, to;
            cin >> from >> to;
            G.push_back({from, to});
        }
        for (int i = 0;i < k;i++) {
            Init(n);
            int occupy;
            cin >> occupy;
            for (int j = 0;j < G.size();j++) {
                if (G[j].first == occupy || G[j].second == occupy)
                    continue;
                Union(G[j].first, G[j].second);
            }
            int num = 0;
            for (int j = 1;j <= n;j++) {
                if (j == occupy)
                    continue;
                if (j == Find(j))
                    num++;
            }
            cout << num - 1 << endl;
        }
    }
    return 0;
}