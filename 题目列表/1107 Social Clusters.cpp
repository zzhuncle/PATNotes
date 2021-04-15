//并查集
//(浙大) https://pintia.cn/problem-sets/994805342720868352/problems/994805361586847744
#include<bits/stdc++.h>
#define MAXN 1001
using namespace std;
int father[MAXN];
int height[MAXN];
int isRoot[MAXN];//记录是否是某个集合的根节点，如果不是为0，是的话记录集合的元素个数
int hobby[MAXN]; //记录hobby对应的同学编号
bool cmp(int a, int b)
{
    return a > b;
}
void Init(int n)
{
    for (int i = 1;i <= n;i++) {
        father[i] = i;
        isRoot[i] = 0;
        hobby[i] = 0;
    }
}
int Find(int x)
{
    if (x != father[x])
        father[x] = Find(father[x]);
    return father[x];
}
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x != y) {
        if (height[x] < height[y]) 
            father[x] = y;
        else if (height[y] < height[x])
            father[y] = x;
        else {
            height[x]++;
            father[y] = x;
        }
    }
}
int str2int(string str)
{
    int n = str.length() - 1;
    int res = 0;
    for (int i = 0;i < n;i++) {
        res *= 10;
        res += str[i] - '0';
    }
    return res;
}
int main()
{
    int n;    //交际网总人数
    cin >> n;
    Init(n);
    for (int i = 1;i <= n;i++) {
        string temp;
        int h;
        cin >> temp;
        int num = str2int(temp);
        for (int j = 0;j < num;j++) {
            cin >> h;
            if (hobby[h] == 0) 
                hobby[h] = i;
            Union(i, Find(hobby[h]));
        }
    }
    for (int i = 1;i <= n;i++)
        isRoot[Find(i)]++;
    int num = 0;
    for (int i = 1;i <= n;i++)
        if (isRoot[i])
            num++;
    cout << num << endl;
    sort(isRoot + 1, isRoot + n + 1, cmp);
    for (int i = 1;i <= num;i++) {
        cout << isRoot[i];
        if (i != num)
            cout << " ";
    }
    cout << endl;
    return 0;
}