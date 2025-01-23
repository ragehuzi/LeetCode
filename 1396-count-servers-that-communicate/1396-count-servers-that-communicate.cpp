class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int answer = 0;

        // Count servers in rows and columns
        vector<int> rowCount(n, 0), colCount(m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }

        // Traverse grid and count communicating servers
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && (rowCount[i] > 1 || colCount[j] > 1))
                {
                    answer++;
                }
            }
        }
        return answer;
    }
};
