//动态规划
#include<bits/stdc++.h>
using namespace std;
int len;
string line;
bool dp[1001][1001] = { {false} };
//i <= j
int solve()
{
    //初始化
    for (int i = 0;i < len;i++) 
        dp[i][i] = true;
    int max = 1;
    for (int i = 0;i < len - 1;i++) {
        dp[i][i + 1] = (line[i] == line[i + 1]);
        if (dp[i][i + 1])
            max = 2;
    }
    for (int k = 2;k <= len - 1;k++) {
        for (int i = 0;i + k < len;i++) {
            if (dp[i + 1][i + k - 1]) {
                dp[i][i + k] = (line[i] == line[i + k]);
                if (dp[i][i + k])
                    max = k + 1;
            }
        }
    }
    return max;
 }
int main()
{
    memset(dp, 0, sizeof(dp));
    getline(cin, line);
    len = line.length();
    cout << solve() << endl;
    return 0;
}