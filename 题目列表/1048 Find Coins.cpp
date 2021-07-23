//狼人杀问题
//分析：每个⼈说的数字保存在v数组中，i从1～n、j从i+1～n遍历，分别假设i和j是狼⼈，a数组表示该
//⼈是狼⼈还是好⼈，等于1表示是好⼈，等于-1表示是狼⼈。k从1～n分别判断k所说的话是真是假，k
//说的话和真实情况不同（即v[k] * a[abs(v[k])] < 0）则表示k在说谎，则将k放在lie数组中；遍历完成后
//判断lie数组，如果说谎⼈数等于2并且这两个说谎的⼈⼀个是好⼈⼀个是狼⼈（即a[lie[0]] + a[lie[1]] ==
//0）表示满⾜题意，此时输出i和j并return，否则最后的时候输出No Solution～
#include<bits/stdc++.h>
using namespace std;
int main() 
{
    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) 
        cin >> v[i];
    for (int i = 1; i <= n; i++) 
        for (int j = i + 1; j <= n; j++) //假设i、j为狼人
        {
            vector<int> lie, a(n + 1, 1);
            a[i] = a[j] = -1;
            for (int k = 1; k <= n; k++)
                if (v[k] * a[abs(v[k])] < 0) 
                    lie.push_back(k);
            if (lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0) {//两个说谎的人，一个狼人、一个平民
                cout << i << " " << j;
                return 0;
            }
        }
    cout << "No Solution";
    return 0;
}