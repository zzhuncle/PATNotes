#include<bits/stdc++.h>
using namespace std;
const int N = 101;
vector<int> G[N];//存放树
int leaf[N];     //存放每层的叶子结点个数
int max_h = 1;   //树的深度
//使用邻接表来存储树，比使用链表结构更简单
void dfs(int id, int depth)
{
    max_h = max(max_h, depth);//更新最大深度
    if (G[id].size() == 0)
        leaf[depth]++;
    for (int i = 0;i < G[id].size();i++)//递归处理子结点
        dfs(G[id][i], depth + 1);
}
//输出每一层的叶子结点个数
int main()
{
    int n, m;//树的结点个数和非叶子结点个数
    cin >> n >> m;
    //root id 01
    int id, k, cid;//父结点的编号 父结点对应子结点的个数
    for (int i = 0;i < m;i++) {
        cin >> id >> k;
        for (int j = 0;j < k;j++) {
            cin >> cid;
            G[id].push_back(cid);
        }
    }
    dfs(1, 1);
    cout << leaf[1];
    for (int i = 2;i <= max_h;i++)
        cout << " " << leaf[i];
    cout << endl;
    return 0;
}
