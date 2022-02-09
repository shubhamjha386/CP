// Algorithms You know
// Brute
// Search   --- Binary Search
// Sort
// Hash
// DP
// Graph
// Recursion  Backtracking
// Pattern
// Mathematical
// Bitwise
// Greedy
// Divide and Conquer
// Stack (Monotonus) Queue (Dequeue) BST Priority Queue
// Sliding Window
// Prefix Sum suffix sum
// Two Pointers

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
long long mod = 10e9 + 7;

int countPrimes(int n)
{
    if (n <= 2)
        return 0;
    vector<bool> primes(n, true);
    primes[0] = primes[1] = false;
    for (int i = 2; i * i < n; i++)
    {
        if (!primes[i])
            continue;
        for (int j = i * i; j < n; j += i)
        {
            primes[j] = false;
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (primes[i])
            count += 1;
    }
    return count;
}

void solve()
{
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;
    ll x5, y5, x6, y6;
    cin >> x5 >> y5 >> x6 >> y6;

    ll w = (x2 - x1) * (y2 - y1);

    if (x4 > x1 and x3 < x2 and y4 > y1 and y3 < y2)
    {
        ll a, b, c, d;
        c = x4 < x2 ? x4 : x2;
        a = x3 > x1 ? x3 : x1;
        d = y4 < y2 ? y4 : y2;
        b = y3 > y1 ? y3 : y1;
        ll length = c - a;
        ll breadth = d - b;

        ll area = length * breadth;
        w -= area;
    }
    if (x6 > x1 and x5 < x2 and y6 > y1 and y5 < y2)
    {
        ll a, b, c, d;
        c = x6 < x2 ? x6 : x2;
        a = x5 > x1 ? x5 : x1;
        d = y6 < y2 ? y6 : y2;
        b = y5 > y1 ? y5 : y1;
        ll length = c - a;
        ll breadth = d - b;

        ll area = length * breadth;
        w = w - area;
    }
    if (w > 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
bool cackum(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4)
{
    if (x1 <= x3 && y1 <= y3 && x2 >= x4 && y2 >= y4)
        return true;
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        string row1,row2;
        cin>>row1>>row2;
        int zero=0,one = 0,ans=0;
        for(int i=0;i<n;i++)
        {
            if(row1[i]=='0' and row2[i]=='0')
            {
                if(one>0)
                    {
                        ans+=2;
                        one = 0;
                    }
                else
                    zero++;
            }
            else if(row1[i]=='1' and row2[i]=='1')
            {
                if(zero>0)
                    {
                        ans += 2 + zero - 1;
                        zero = 0;
                    }
                else
                    one++;
            }
            else
            {
                ans += zero;
                ans +=2;
                zero = 0;
                one = 0;
            }
        }
        if(zero>0)
            ans += zero;
        cout<<ans<<endl;
    }
    return 0;
}