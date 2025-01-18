class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> minCost(rows, vector<int>(cols, INT_MAX));
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // Right, Left, Down, Up
        
        deque<pair<int, int>> dq;
        dq.push_back({0, 0}); // {row, col}
        minCost[0][0] = 0;

        while (!dq.empty()) {
            auto [row, col] = dq.front();
            dq.pop_front();

            for (int dir = 0; dir < 4; dir++) {
                int nextRow = row + dirs[dir][0];
                int nextCol = col + dirs[dir][1];

                if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols) {
                    int cost = minCost[row][col];
                    int nextCellCost = (dir + 1 == grid[row][col]) ? 0 : 1;
                    int newCost = cost + nextCellCost;

                    if (newCost < minCost[nextRow][nextCol]) {
                        minCost[nextRow][nextCol] = newCost;
                        if (nextCellCost == 0) {
                            dq.push_front({nextRow, nextCol});
                        } else {
                            dq.push_back({nextRow, nextCol});
                        }
                    }
                }
            }
        }

        return minCost[rows - 1][cols - 1];
    }
};
