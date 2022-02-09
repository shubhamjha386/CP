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

bool isSorted(int arr[], int l, int h)
{
    for (int i = l + 1; i < h; i++)
        if (arr[i] != arr[i - 1] + 1)
            return false;
    return true;
}
bool isAsorted(int arr[], int l, int h)
{
    for (int i = l + 1; i < h; i++)
        if (arr[i] != arr[i - 1] - 1)
            return false;
    return true;
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (!((abs(arr[i] - arr[i - 1]) == 1) || (arr[i] == 1 && arr[i - 1] == n) || (arr[i - 1] == 1 && arr[i] == n)))
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
        // solve();
        int n;
        cin >> n;
        string str;
        cin >> str;
        int ca = 0, cb = 0, count = 0;
        for (int j = 0; j < n; j += 2)
        {
            for (int i = j; i < j + 2; i++)
            {
                if (str[i] == 'a')
                    ca++;
                else
                    cb++;
                if (ca - cb > 1)
                {
                    str[i] = 'b';
                    ca--;
                    cb++;
                    count++;
                }
                else if (cb - ca > 1)
                {
                    str[i] = 'a';
                    cb--;
                    ca++;
                    count++;
                }
            }
        }
        cout << count << endl;
        cout << str << endl;
    }
    return 0;
}