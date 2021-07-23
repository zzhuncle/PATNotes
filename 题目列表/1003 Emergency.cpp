/*  题⽬⼤意：n个城市m条路，每个城市有救援⼩组，所有的边的边权已知。给定起点和终点，求从起点
到终点的最短路径条数以及最短路径上的救援⼩组数⽬之和。如果有多条就输出点权（城市救援⼩组
数⽬）最⼤的那个～
    分析：⽤⼀遍Dijkstra算法～救援⼩组个数相当于点权，⽤Dijkstra求边权最⼩的最短路径的条数，以及
这些最短路径中点权最⼤的值～dis[i]表示从出发点到i结点最短路径的路径⻓度，num[i]表示从出发点
到i结点最短路径的条数，w[i]表示从出发点到i点救援队的数⽬之和～当判定dis[u] + e[u][v] < dis[v]的时
候，不仅仅要更新dis[v]，还要更新num[v] = num[u], w[v] = weight[v] + w[u]; 如果dis[u] + e[u][v] ==
dis[v]，还要更新num[v] += num[u]，⽽且判断⼀下是否权重w[v]更⼩，如果更⼩了就更新w[v] =
weight[v] + w[u]; */
#include<bits/stdc++.h>
#define MAX 501
#define INF 99999999
using namespace std;
int cost[MAX][MAX];//cost[i][j]表示边e=(u,v)的权值(不存在这条边时设为INF)
int dis[MAX];      //顶点s出发的最短距离
int num[MAX];      //从出发点到i结点最短路径的条数
int w[MAX];        //从出发点到i结点救援队的数目之和
bool used[MAX];    //已经使用过的图
int weight[MAX];   //救援队数量

void dijkstra(int s, int n)
{
    fill(dis, dis + MAX, INF);
    fill(used, used + MAX, false);
    
    dis[s] = 0;
    w[s] = weight[s];
    num[s] = 1;
    while (true) {
        int v = -1;
        //从尚未使用过的顶点中选择一个距离最小的顶点
        for (int u = 0;u < n;u++)
            if (!used[u] && (v == -1 || dis[u] < dis[v]))
                v = u;
        if (v == -1)
            break;
        used[v] = true;
        for (int u = 0;u < n;u++) {
            if (cost[v][u] != INF) {
                if (dis[v] + cost[v][u] < dis[u]) {
                    dis[u] = dis[v] + cost[v][u];
                    num[u] = num[v];
                    w[u] = w[v] + weight[u];
                }
                else if (dis[v] + cost[v][u] == dis[u]) {
                    num[u] += num[v];
                    if (w[v] + weight[u] > w[u])
                        w[u] = w[v] + weight[u];
                }
            }
        }
    }
}
int main()
{
    int n, m, c1, c2;
    cin >> n >> m >> c1 >> c2;
    for (int i = 0;i < n;i++)
        cin >> weight[i];
    int from, to, c;
    fill(cost[0], cost[0] + MAX * MAX, INF);
    for (int i = 0;i < m;i++) {
        cin >> from >> to  >> c;
        cost[from][to] = cost[to][from] = c;
    }
    dijkstra(c1, n);
    cout << num[c2] << " " << w[c2] << endl;
    return 0;
}