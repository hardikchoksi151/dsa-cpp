#include <bits/stdc++.h>
using namespace std;

void sort(vector<int> &);
void insert(vector<int> &, int);

int main()
{
    vector<int> v = {2, 4, 3, 1};
    sort(v);

    for (int i : v)
        cout << i << endl;

    return 0;
}

void sort(vector<int> &v)
{
    if (v.size() == 1)
        return;

    int lastElement = v[v.size() - 1];
    v.pop_back();

    sort(v);

    insert(v, lastElement);
}

void insert(vector<int> &v, int x)
{
    if (v.size() == 0 || v[v.size() - 1] <= x)
    {
        v.push_back(x);
        return;
    }

    int lastElement = v[v.size() - 1];

    v.pop_back();

    insert(v, x);

    v.push_back(lastElement);
}