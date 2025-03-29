#include <bits/stdc++.h>
using namespace std;

// string rowToString(vector<vector<int>> &m, int r)
// {
//     int N = m[0].size();
//     string res = "";
//     int base = m[r][0]; // Use the first element to determine the base form

//     for (int i = 0; i < N; ++i)
//     {
//         // Transform row into its canonical form
//         res += (m[r][i] == base ? '0' : '1');
//     }

//     return res;
// }

string rowToString(vector<vector<int>> &m, int r)
{
    string res = "";

    int base = m[r][0];

    for (int i = 0; i < m[0].size(); i++)
        res += base ? m[r][i] == 0 ? '1' : '0' : m[r][i] == 0 ? '0'
                                                              : '1';

    return res;
}

int main()
{
    int M, N;
    cin >> M >> N;

    // create a M * N matrix
    vector<vector<int>> matrix(M, vector<int>(N));

    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            cin >> matrix[i][j];

    for (int r = 0; r < M; ++r)
        cout
            << rowToString(matrix, r) << endl;
}