#include <bits/stdc++.h>
using namespace std;

void delelteKth(stack<int> &, int);

int main()
{
    int temp, k;
    stack<int> st;

    cin >> k;

    while (cin >> temp)
    {
        st.push(temp);
    }

    delelteKth(st, k);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}

void delelteKth(stack<int> &st, int k)
{
    // base condition
    if (k == 1)
    {
        st.pop();
        return;
    }

    // Hypothesis
    int lastElement = st.top(); // A. make smaller input
    st.pop();

    delelteKth(st, k - 1); // B. hypothesis step

    // Induction
    st.push(lastElement);
}