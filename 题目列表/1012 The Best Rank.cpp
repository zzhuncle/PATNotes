#include<bits/stdc++.h>
using namespace std;
struct Student
{
    int id;      //存放6位整数的ID
    int grade[4];//存放4个分数
};
Student stu[2010];
char course[4] = {'A', 'C', 'M', 'E'};//按优先级顺序，方便输出
int Rank[1000000][4] = {0};//Rank[id][0]~Rank[id][3]为4门课对应的排名
int now;//cmp函数中使用，表示当前按now号分数排序stu数组
bool cmp(Student a, Student b)//stu数组按now号分数递减排序
{
    return a.grade[now] > b.grade[now];
}
int main()
{
    int n, m;
    cin >> n >> m;
    //读入分数，其中grade[0] ~ grade[3]分别代表ACME
    for (int i = 0;i < n;i++) {
        cin >> stu[i].id >> stu[i].grade[1] >> stu[i].grade[2] >> stu[i].grade[3];
        stu[i].grade[0] = stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3];
    }
    for (now = 0;now < 4;now++) {
        sort(stu, stu + n, cmp);//对所有考生按该分数从大到小排序
        Rank[stu[0].id][now] = 1;//排完序，将分数最高的设为rank1
        for (int i = 1;i < n;i++) {//对于剩下的考生
            //若与前一位考生分数相同
            if (stu[i].grade[now] == stu[i - 1].grade[now]) 
                Rank[stu[i].id][now] = Rank[stu[i - 1].id][now];//则他们排名相同
            else
                Rank[stu[i].id][now] = i + 1;//否则，为其设置正确的排名
        }
    }
    int query;//查询的考生ID
    for (int i = 0;i < m;i++) {
        cin >> query;
        if (Rank[query][0] == 0)//如果考生不存在，输出'N/A'
            cout << "N/A" << endl;
        else {
            int k = 0;
            for (int j = 0;j < 4;j++)
                if (Rank[query][j] <Rank[query][k])
                    k = j;
            cout << Rank[query][k] << " " << course[k] << endl;
        }
    }
    return 0;
}