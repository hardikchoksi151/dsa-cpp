#include<bits/stdc++.h>
using namespace std;

int backtrack(vector<vector<int>> &questions, vector<int> &cache, int i) {
  if (cache[i] > 0)
    return cache[i];
  if (i == questions.size())
    return 0;

  int points     = questions[i][0];
  int brainPower = questions[i][1];

  int r1 = backtrack(questions, i + 1); // not choose
  int r2 = points + backtrack(questions, i + 1 + brainPower); // choose

  return cache[i] = max(r1, r2);
}

long long bottom_up(vector<vector<int>>& questions) {
  int N = questions.size();
  vector<int> cache(N, 0);

  for (int i = N - 1; i >= 0; --i) {
    int points     = questions[i][0];
    int brainPower = questions[i][1];
    int next_i     = i + 1 + brainPower;
    
    long long choose  = points + next_i < N ? next_i : 0;
    long long nChoose = i + 1 < N ? i + 1 : 0;

    cache[i] = max(choose, nChoose);
  }

  return cache[0];
}

long long mostPoints(vector<vector<int>>& questions) {
  vector<int> cache(quesions.size(), 0);
  return backtrack(questions, cache, 0);       
}

int main() {

  return 0;
}
