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
long long mod = 10e9 + 7;

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

void solve()
{
    int n;
    cin >> n;
    ll k[n];
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    }

    for (int i = 0; i < n; i++)
    {
        ll j = 1;
        while (k[i])
        {
            if (k[i] <= to_string(j).size())
            {
                string tmp = to_string(j);
                cout << tmp[k[i] - 1] << endl;
            }
            else
            {
                k[i] -= to_string(j).size();
                j++;
            }
        }
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
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}