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
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    int mino = INT_MAX;

    for (int i = 0; i <= n - k; i++)
    {
        int j = i, mine = arr[j];
        while (j < n and arr[j] == mine)
            j++;
        if (j == i + k)
        {
            cout << 0 << endl;
            return;
        }
        int tmp = 0;
        while (j < i + k)
        {
            tmp += (arr[j] - arr[i] + 1) / 2;
            j++;
        }
        mino = min(mino, tmp);
    }
    cout << mino << endl;
}

static bool compare(pll a,pll b)
{
    if(a.first==b.first)
    {
        return a.second>b.second;
    }
    return a.first<b.first;
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
        ll n,m;
        cin>>n>>m;
        vector<pll> ps;
        for(ll i=0;i<n*m;i++)
            {
                int x;
                cin>>x;
                ps.push_back({x,i+1});
            }
        sort(ps.begin(),ps.end(),compare);
        int seats[m+1];
        for(int i=1;i<=n*m;i++)
        {
            seats[ps[i-1].second] = i;
        }
        int occupied[m+1] = {0};
        occupied[seats[1]]++;
        ll total = 0;
        for(int i=2;i<=n*m;i++)
        {
            ll o = 0;
            for(int j=1;j<seats[i];j++)
            {
                if(occupied[j])
                    o++;
            }
            total += o;
            occupied[seats[i]]++;
        }
        cout<<total<<endl;

    }
    return 0;
}