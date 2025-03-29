#include <bits/stdc++.h>
using namespace std;

void sort(stack<int> &);
void insert(stack<int> &, int);

int main()
{
    stack<int> st;

    vector<int> v = {2, 4, 3, 1};

    for (int &i : v)
        st.push(i);

    sort(st);

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}

void sort(stack<int> &st)
{
    if (st.size() == 1)
        return;

    int lastElement = st.top();
    st.pop();

    sort(st);

    insert(st, lastElement);
}

void insert(stack<int> &st, int x)
{
    if (st.size() == 0 || st.top() <= x)
    {
        st.push(x);
        return;
    }

    int lastElement = st.top();

    st.pop();

    insert(st, x);

    st.push(lastElement);
}