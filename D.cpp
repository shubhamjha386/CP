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
typedef vector<long long> vll;
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
int sqr(int x)
{
    return x * x;
}
constexpr int MAXSUM = 100 * 100 + 10;
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

bool isPalindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
ll solve(vector<ll> &arr, vector<vector<ll>> &dp, ll &k, ll i, ll time)
{
    if (time > k)
        return 0;
    if (i < 0)
        return time - 1 + solve(arr, dp, k, i + 1, time + 1);
    if (i == arr.size())
        return time - 1 + solve(arr, dp, k, i - 1, time + 1);
    if (dp[i][time] != -1)
        return dp[i][time];
    if (time == 0)
        return dp[i][time] = max({solve(arr, dp, k, i + 1, time + 1), solve(arr, dp, k, i, time + 1),
                                  solve(arr, dp, k, i - 1, time + 1)});
    return dp[i][time] = arr[i] + time - 1 + max({solve(arr, dp, k, i + 1, time + 1), solve(arr, dp, k, i, time + 1), solve(arr, dp, k, i - 1, time + 1)});
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
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        ll maxi = -1;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (maxi == -1)
                maxi = i;
            else if (arr[i] > arr[maxi])
                maxi = i;
        }

        ll ans = 0;
        vector<vector<ll>> dp(n, vector<ll>(k + 1, -1));
        ll time = 0;
        ans = max(ans, solve(arr, dp, k, maxi, time));
        cout << ans << endl;
    }
    return 0;
}