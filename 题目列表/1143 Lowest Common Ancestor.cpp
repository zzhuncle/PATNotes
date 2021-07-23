//题⽬⼤意：给出⼀棵⼆叉搜索树的前序遍历，问结点u和v的共同最低祖先是谁～
//主要是只给出前序遍历，无法确定树的形状，所以就不会求共同最低祖先了，吐了，怎么稍微变一下就不会了
//其实不需要确定树的形状，将当前结点标记为a，如果u和v分别在a的左、右，或者u、v其中⼀个就是当前a，说明找到了这个共同最低祖先a
//即(a >= u && a <= v) || (a >= v && a <= u) 主要利用二叉搜索树的性质
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> pre(n, 0);
    map<int, bool> mp;
    for (int i = 0;i < n;i++) {
        cin >> pre[i];
        mp[pre[i]] = true;
    }
    int u, v, a;
    for (int i = 0;i < m;i++) {
        cin >> u >> v;
        for (int j = 0;j < n;j++) { 
            a = pre[j];
            if ((u <= a && a <= v) || (v <= a && a <= u))
                break;
        }
        if (mp[u] == false && mp[v] == false)
            cout << "ERROR: " << u << " and " << v << " are not found." << endl;
        else if (mp[u] == false)
            cout << "ERROR: " << u << " is not found." << endl;
        else if (mp[v] == false)
            cout << "ERROR: " << v << " is not found." << endl;
        else if (u == a)
            cout << u << " is an ancestor of " << v << "." << endl;
        else if (v == a)
            cout << v << " is an ancestor of " << u << "." << endl;
        else 
            cout << "LCA of " << u << " and " << v << " is " << a << "." << endl;
    }
    return 0;
}
