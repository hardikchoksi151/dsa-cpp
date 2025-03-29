#include <bits/stdc++.h>
typedef std::stack<int> st;
using namespace std;

void insert(st &, int);
void reverse(st &);

int main()
{
    int temp;
    st st;

    while (cin >> temp)
    {
        st.push(temp);
    }

    reverse(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}

void reverse(st &st)
{
    // base condition - when stack contains just one element, its already reversed
    if (st.size() == 1)
        return;

    // hypothesis - smaller the input and assume function works for smaller one
    int lastElement = st.top();
    st.pop();
    reverse(st);

    // induction - insert last element that was removed @ first position of stack / base pointer of stack.
    insert(st, lastElement);
}

void insert(st &st, int k)
{
    // base condition - when stack size is zero, just add k to top
    if (st.empty())
    {
        st.push(k);
        return;
    }

    // hypothesis - remove last element (make i/p smaller), and call function
    int lastElement = st.top();
    st.pop();
    insert(st, k);

    // induction - when k in inserted at base of stack, just add last element back to top of stack
    st.push(lastElement);
}