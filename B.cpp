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
// Stack (Monotonus)
// Queue (Dequeue)
// BST
// Priority Queue
// Sliding Window
// Prefix Sum suffix sum
// Two Pointers
// Disjoint Sets
// Segment Trees

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
long long mod = 1e9 + 7;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
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
bool checkSorted(vector<ll> ans)
{
    for (ll i = 1; i < ans.size(); i++)
    {
        if (ans[i] < ans[i - 1])
            return false;
    }
    return true;
}
long long binpow(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

static bool compare(pii a, pii b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}
int setBitNumber(int x)
{
    ll i = 0;
    while (x > 0)
    {
        if (x & 1)
            break;
        else
        {
            i++;
            x = x >> 1;
        }
    }
    return i;
}
void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
        for (int j = n; j >= 1; j--)
        {
            if (j != i)
                cout << j << " ";
        }
        cout << endl;
    }
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
        cin >> n;
        int arr[n];
        int even = 0, odd = 0, tmp = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] & 1)
                odd++;
            else
            {
                even++;
                for (int j = 0; j < 32; j++)
                {
                    if (arr[i] & (1 << j))
                    {
                        tmp = min(tmp, j);
                        break;
                    }
                }
            }
        }
        if (odd == 0)
        {
            cout << tmp + even - 1 << endl;
        }
        else
        {
            cout << even << endl;
        }
    }
    return 0;
}