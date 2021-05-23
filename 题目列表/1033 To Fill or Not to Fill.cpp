//1033 To Fill or Not to Fill https://pintia.cn/problem-sets/994805342720868352/problems/994805458722734080
//题目需要考虑的细节比较多，详情见注释

#include<bits/stdc++.h>
using namespace std;
const int maxn = 510;//最多的站点数
const int INF = 1e8;
struct station
{
    double price;    //汽油价格
    double dis;      //起点的距离
};
station st[maxn];
bool cmp(station a, station b)
{
    return a.dis < b.dis; //按距离从小到大排序
}
int main()
{
    int n;
    double Cmax, D, Davg; //油箱容量、起终点距离、每升汽油距离
    scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &n);
    for (int i = 0;i < n;i++)
        scanf("%lf%lf", &st[i].price, &st[i].dis);
    st[n].price = 0;      //数据最后放置终点，价格为0
    st[n].dis = D;        //终点距离为D
    sort(st, st + n, cmp);//将所有加油站按距离从小到大排序
    if (st[0].dis != 0) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    int now = 0;//当前所处的加油站编号
    //总花费、当前油量及满油行驶距离
    double ans = 0, nowTank = 0, MAX = Cmax * Davg;
    while (now < n) {//每次循环将选出下一个需要到达的加油站
    //选出从当前加油站满油能到达范围内的第一个油价低于当前油价的加油站
        //如果没有低于当前油价的加油站，则选择价格最低的那个
        int k = -1;            //最低油价的加油站编号
        double priceMin = INF; //最低油价
        for (int i = now + 1;i <= n && st[i].dis - st[now].dis <= MAX;i++) {
            if (st[i].price < priceMin) {//如果油价比当前最低油价低
                priceMin = st[i].price;//更新最低油价
                k = i;
            }
            //如果找到第一个油价低于当前油价的加油站，直接中断循环
            if (priceMin < st[now].price)
                break;
        }
        if (k == -1)//如果满油状态下无法找到加油站，退出循环输出结果
            break;
        //下面为能找到可能到达的加油站k，计算转移花费
        //need 为从now到k需要的加油量
        double need = (st[k].dis - st[now].dis) / Davg;
        if (priceMin < st[now].price) {//如果加油站k的油价低于当前油价
            //只买足够到达加油站k的油
            if (nowTank < need) {//如果当前油量不足need
                ans += (need - nowTank) * st[now].price;//补足need
                nowTank = 0;//到达加油站k后油箱内油量为0
            } else {
                nowTank -= need;//直接到达加油站k
            }
        } 
        else {//如果加油站k的油价高于当前油价
            ans += (Cmax - nowTank) * st[now].price;//将油箱加满
            nowTank = Cmax - need;
        }
        now = k;//到达加油站k，进入下一层循环
    }
    if (now == n) //能到达终点
        printf("%.2f\n", ans);
    else 
        printf("The maximum travel distance = %.2f\n", st[now].dis + MAX);
    return 0;
}
