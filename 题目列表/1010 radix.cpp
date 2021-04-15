//二分法
#include<bits/stdc++.h>
using namespace std;
string n1, n2;
//进制和二分法
long long char2ll(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return ch - 'a' + 10;
    else
        return ch - '0';
}
long long solve(long long l, long long r, long long res, string str)
{
    long long temp = 0;
    while (l <= r) {
        long long mid = l + (r - l) / 2;
        temp = 0;
        for (int j = 0;j < str.size();j++) {
            temp *= mid;
            temp += char2ll(str[j]);
        }
        if (temp == res)
            return mid;
        else if (temp > res || temp < 0)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
int main()
{

    int tag;
    long long radix;
    cin >> n1 >> n2 >> tag >> radix;
    long long res = 0;
    if (n1 == n2 && n1 == "0") {
        cout << 2 << endl;
        return 0;
    }
    if (tag == 1) {
        long long max_x = -1;
        for (int i = 0;i < n1.size();i++) {
            res *= radix;
            res += char2ll(n1[i]);
            
        }
        for (int i = 0;i < n2.size();i++)
            max_x = max(max_x, char2ll(n2[i]));
        long long ans = solve(max_x + 1, res + 1, res, n2);
        if (ans != -1) {
            cout << ans << endl;
            return 0;
        }
    } 
    else {
        long long max_x = -1;
        for (int i = 0;i < n2.size();i++) {
            res *= radix;
            res += char2ll(n2[i]);
        }
        for (int i = 0;i < n1.size();i++)
            max_x = max(max_x, char2ll(n1[i]));
        long long ans = solve(max_x + 1, res + 1, res, n1);
        if (ans != -1) {
            cout << ans << endl;
            return 0;
        }
    }
    cout << "Impossible" << endl;
    return 0;
}