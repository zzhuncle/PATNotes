#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, now = 0, sum = 0;
    cin >> a;
    while (cin >> a) {
        if (a > now)
            sum += 6 * (a - now);
        else if (a < now)
            sum += 4 * (now - a);
        now = a;
        sum += 5;
    }
    cout << sum << endl;
    return 0;
}