#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));

    dp[0][0] = grid[0][0];

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (i > 0)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
            }
            if (j > 0)
            {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
            }
        }
    }

    return dp[rows - 1][cols - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix( n , vector<int> (m)); 
    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < m ; j++) cin >> matrix[i][j];
    }
    cout << "Minimum cost is " << minPathSum(matrix) << endl;

    return 0;
}
