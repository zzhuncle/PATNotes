//并查集
//翻译题目需要精确，需要注意的是团伙的人数大于2（等于2也不可以），团伙总通话时长大于阈值K而不是最大的时长大于K
#include<bits/stdc++.h>
using namespace std;
#define MAXN 2001
int height[MAXN];
int father[MAXN];
int call[MAXN];
map<string, int> s2i;
map<int, string> i2s;
struct node {
    int cnt;
    int head;
    int total_call;
	bool operator<(const node &b) const {
		return i2s[head] < i2s[b.head];
	}
} gang [MAXN];
void Init()
{
    for (int i = 0;i < MAXN;i++) {
        height[i] = 1;
        father[i] = i;
        call[i] = 0;
    }
}
int Find(int x)
{
    if (x != father[x]) {
        x = Find(father[x]);
    }
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
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int size, n, k;
    while (cin >> n >> k) {
        Init();
        size = 1; s2i.clear(); i2s.clear();
        string m1, m2;
        int time, n1, n2;
        for (int i = 0;i < n;i++) {
            cin >> m1 >> m2 >> time;
            if (!s2i.count(m1)) {
                i2s[size] = m1;
                s2i[m1] = size++;
            }
            if (!s2i.count(m2)) {
                i2s[size] = m2;
                s2i[m2] = size++;
            }
            n1 = s2i[m1], n2 = s2i[m2];
            call[n1] += time, call[n2] += time;
            Union(n1, n2);
        }
        for (int i = 1;i < size;i++) {
            int root = Find(i);
            gang[root].cnt++;
            gang[root].total_call += call[i];
            if (call[i] > call[gang[root].head]) 
                gang[root].head = i;
        }
        set<node> gangSet;
        for (int i = 1;i < size;i++)
            if (i == Find(i))
                if (gang[i].cnt > 2 && gang[i].total_call > 2 * k)
                    gangSet.insert(gang[i]);
        cout << gangSet.size() << endl;
        set<node>::iterator it;
        for (it = gangSet.begin();it != gangSet.end();it++) {
            cout << i2s[it->head] << " " << it->cnt << endl;
        }
    }
    return 0;
}