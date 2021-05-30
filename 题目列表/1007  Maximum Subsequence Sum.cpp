//最大连续子序列 http://t.cn/AiYoUkjP
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10001;
int arr[MAXN];
int dp[MAXN];
int begi[MAXN];
int main()
{
    int n;
    bool flag = true;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> arr[i];
        if (arr[i] >= 0)
            flag = false;
    }
    if (flag) {
        cout << 0 << " " << arr[1] << " " << arr[n] << endl;
        return 0;
    }
    int max = -1, begini = 0, endi = 0;
    for (int i = 1;i <= n;i++) {
        if (i == 1) {
            dp[1] = arr[1];
            begi[1] = 1;
        }
        else {
            if (arr[i] < dp[i - 1] + arr[i]) {
                dp[i] = dp[i - 1] + arr[i];
                begi[i] = begi[i - 1];
            }
            else {
                dp[i] = arr[i];
                begi[i] = i;
            }
        }
        if (dp[i] > max) {
            max = dp[i];
            begini = begi[i];
            endi = i;
        }
    }
    cout << max << " " << arr[begini] << " " << arr[endi] << endl;
    return 0;
}