class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // First we mark the water blocks with the height 1
        for (int i = 0; i < isWater.size(); i++)
        {
            for (int j = 0; j < isWater[0].size(); j++)
            {
                if (isWater[i][j] == 1)
                {
                    visited[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            pair<int, int> temp = q.front();
            q.pop();

            pair<int, int> up = {temp.first - 1, temp.second};    // up -> r - 1 && c
            pair<int, int> down = {temp.first + 1, temp.second};  // down -> r + 1 && c
            pair<int, int> left = {temp.first, temp.second - 1};  // left -> r && c - 1
            pair<int, int> right = {temp.first, temp.second + 1}; // right -> r && c + 1

            if (up.first >= 0 && up.first < m && up.second >= 0 && up.second < n && visited[up.first][up.second] == -1)
            {
                visited[up.first][up.second] = 1 + visited[temp.first][temp.second];
                q.push({up.first, up.second});
            }

            if (down.first >= 0 && down.first < m && down.second >= 0 && down.second < n && visited[down.first][down.second] == -1)
            {
                visited[down.first][down.second] = 1 + visited[temp.first][temp.second];
                q.push({down.first, down.second});
            }

            if (left.first >= 0 && left.first < m && left.second >= 0 && left.second < n && visited[left.first][left.second] == -1)
            {
                visited[left.first][left.second] = 1 + visited[temp.first][temp.second];
                q.push({left.first, left.second});
            }

            if (right.first >= 0 && right.first < m && right.second >= 0 && right.second < n && visited[right.first][right.second] == -1)
            {
                visited[right.first][right.second] = 1 + visited[temp.first][temp.second];
                q.push({right.first, right.second});
            }
        }
        return visited;
    }
};