/*  分析：⽤vector v[n]保存某结点属于的某条边的编号，⽐如a b两个结点构成的这条边的编号为0，则
v[a].push_back(0)，v[b].push_back(0)——表示a属于0号边，b也属于0号边。对于每⼀个集合做判断，
遍历集合中的每⼀个元素，将当前元素能够属于的边的编号i对应的hash[i]标记为1，表示这条边是满
⾜有⼀个结点出⾃集合S中的。最后判断hash数组中的每⼀个值是否都是1，如果有不是1的，说明这条
边的两端结点没有⼀个出⾃集合S中，则输出No。否则输出Yes～  */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m;
    vector<vector<int>> v(n);
    int s, e;
    for (int i = 0;i < m;i++) {
        cin >> s >> e;
        v[s].emplace_back(i);
        v[e].emplace_back(i);
    }
    cin >> k;
    for (int i = 0;i < k;i++) {
        vector<int> hash(m, 0);
        int kn, index;
        cin >> kn;
        for (int j = 0;j < kn;j++) {
            cin >> index;
            for (int u = 0;u < v[index].size();u++)
                hash[v[index][u]] = 1;
        }
        bool flag = true;
        for (int j = 0;j < m;j++)
            if (hash[j] != 1) {
                flag = false;
                break;
            }
        cout << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}