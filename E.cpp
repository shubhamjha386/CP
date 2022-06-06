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
void solve()
{
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
        map<string, vector<int>> m;
        int n;
        cin >> n;
        vector<string> str(n);
        for (int i = 0; i < n; i++)
        {
            cin >> str[i];
            m[str[i]].push_back(i);
        }
        long long ans = 0, idx;
        string word;
        for (int i = 0; i < n; i++)
        {
            // Check First Character
            word = str[i];
            char first = word[0];
            for (char c = 'a'; c <= 'k'; c++)
            {
                if (c != first)
                {
                    word[0] = c;
                    if (m.find(word) != m.end())
                    {
                        idx = lower_bound(m[word].begin(), m[word].end(), i) - m[word].begin();
                        ans += ((ll)m[word].size() - idx);
                    }
                }
            }
            // Check Last Character
            word = str[i];
            first = word[1];
            for (char c = 'a'; c <= 'k'; c++)
            {
                if (c != first)
                {
                    word[1] = c;
                    if (m.find(word) != m.end())
                    {
                        idx = lower_bound(m[word].begin(), m[word].end(), i) - m[word].begin();
                        ans += ((ll)m[word].size() - idx);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}