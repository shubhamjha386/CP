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
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int count = 0;
    int mine = arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>mine)
            count++;
        else
            mine = arr[i];
    }
    cout<<count<<endl;
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
    int t=1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            arr.push_back({x,i});
        }
        sort(arr.begin(),arr.end());
        int total = 0;
        for(int i=n-1;i>=0;i--)
        {
            total += (arr[i].first*(n-1-i) + 1);
        }
        cout<<total<<endl;
        for(int i=n-1;i>=0;i--)
            cout<<arr[i].second+1<<" ";

    }
    return 0;
}