#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    int *parent, *rank, n;

public:
    DisjointSet(int n)
    {
        parent = new int[n];
        rank = new int[n];
        this->n = n;
        setValues();
    }
    void setValues()
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int findParent(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = findParent(parent[x]);
    }
    void Union(int x, int y)
    {
        int a = findParent[x];
        int b = findParent[y];
        if (a == b)
            return;
        if (rank[a] < rank[b])
            parent[a] = b;
        else if (rank[a] > rank[b])
            parent[b] = a;
        else
        {
            parent[b] = a;
            rank[a]++;
        }
    }
};
int main()
{
    DisjointSet obj(5);
    obj.Union(1, 2);
    obj.Union(2, 3);
    obj.Union(3, 4);
    cout << obj.findParent(2) << endl;
    return 0;
}