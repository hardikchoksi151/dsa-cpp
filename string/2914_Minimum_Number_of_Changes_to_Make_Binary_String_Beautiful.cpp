#include <bits/stdc++.h>
using namespace std;

int minChanges(string);
int minChanges2(string);

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    cout << minChanges2(str) << endl;
    return 0;
}

int minChanges(string s)
{
    int n = s.length();

    char ch = s[0];
    int count = 0, changes = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == ch)
        {
            count++;
            continue;
        }

        if (count % 2 == 0)
        {
            count = 1;
        }
        else
        {
            changes++;
            count = 0;
        }
        ch = s[i];
    }

    return changes;
}

int minChanges2(string s)
{
    int changes = 0;

    for (int i = 0; i < s.length(); i += 2)
        if (s[i] != s[i + 1])
            changes++;

    return changes;
}