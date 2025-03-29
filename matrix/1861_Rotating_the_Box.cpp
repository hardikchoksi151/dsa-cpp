#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> rotate90Degree(vector<vector<char>> &box)
{
    int M = box.size();
    int N = box[0].size();
    vector<vector<char>> res(N, vector<char>(M));

    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            res[j][M - 1 - i] = box[i][j];

    return res;
}

vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
{
    int M = box.size();
    int N = box[0].size();

    for (auto &row : box)
    {
        int space = N - 1;
        for (int i = N - 1; i >= 0; --i)
        {
            if (row[i] == '#')
            {
                swap(row[i], row[space]);
                --space;
            }
            else if (row[i] == '*')
            {
                space = i - 1;
            }
        }
    }

    return rotate90Degree(box);
}

int main()
{
    int M, N;
    cin >> M >> N;
    vector<vector<char>> box(M, vector<char>(N));

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> box[i][j];

    auto res = rotateTheBox(box);

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //         cout << res[i][j] << " ";
    //     cout << endl;
    // }
    for (auto &row : res)
    {
        for (char &ch : row)
            cout << ch << " ";
        cout << endl;
    }
}