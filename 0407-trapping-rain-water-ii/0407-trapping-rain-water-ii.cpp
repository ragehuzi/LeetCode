class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        vector<vector<bool>> visited(heightMap.size(), vector<bool>(heightMap[0].size(), false));
        int level = 0;
        int answer = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> Q; // min-heap

        // First push all the boundaries into the Q
        // Make them visited and mark true in the visited array
        int i = 0, j = 0;
        while (j < heightMap[0].size())
        {
            Q.push(make_tuple(heightMap[i][j], i, j));
            visited[i][j] = true;
            j++;
        }
        i = 0; // Reset i
        j = heightMap[0].size() - 1; // Set j to the last column
        while (i < heightMap.size())
        {
            Q.push(make_tuple(heightMap[i][j], i, j));
            visited[i][j] = true;
            i++;
        }
        i = heightMap.size() - 1; // Set i to the last row
        j = heightMap[0].size() - 1; // Reset to the last column
        while (j >= 0)
        {
            Q.push(make_tuple(heightMap[i][j], i, j));
            visited[i][j] = true;
            j--;
        }
        i = heightMap.size() - 1; // Reset to the last row
        j = 0; // Reset to the first column
        while (i >= 0)
        {
            Q.push(make_tuple(heightMap[i][j], i, j));
            visited[i][j] = true;
            i--;
        }

        tuple<int, int, int> temp;

        // Now start popping out and comparing with the level
        while (!Q.empty())
        {
            temp = Q.top();
            Q.pop();

            int height = get<0>(temp);
            int row = get<1>(temp);
            int col = get<2>(temp);

            level = max(level, height);

            // Check for the neighbors (up, down, right, left)
            if (row + 1 < heightMap.size() && !visited[row + 1][col])
            {
                if (heightMap[row + 1][col] < level)
                {
                    answer += (level - heightMap[row + 1][col]);
                }
                Q.push(make_tuple(heightMap[row + 1][col], row + 1, col));
                visited[row + 1][col] = true;
            }

            if (row - 1 >= 0 && !visited[row - 1][col])
            {
                if (heightMap[row - 1][col] < level)
                {
                    answer += (level - heightMap[row - 1][col]);
                }
                Q.push(make_tuple(heightMap[row - 1][col], row - 1, col));
                visited[row - 1][col] = true;
            }

            if (col + 1 < heightMap[0].size() && !visited[row][col + 1])
            {
                if (heightMap[row][col + 1] < level)
                {
                    answer += (level - heightMap[row][col + 1]);
                }
                Q.push(make_tuple(heightMap[row][col + 1], row, col + 1));
                visited[row][col + 1] = true;
            }

            if (col - 1 >= 0 && !visited[row][col - 1])
            {
                if (heightMap[row][col - 1] < level)
                {
                    answer += (level - heightMap[row][col - 1]);
                }
                Q.push(make_tuple(heightMap[row][col - 1], row, col - 1));
                visited[row][col - 1] = true;
            }
        }

        return answer;
    }
};
