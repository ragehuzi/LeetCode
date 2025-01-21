class Solution
{
public:
    long long gridGame(vector<vector<int>> &grid)
    {
        long long sum = 0;
        long long bottomSum = 0;

        long long answer = LONG_LONG_MAX;

        // First take the sum of the Above Row
        for (auto i : grid[0])
            sum += i;

        for (int i = 0; i < grid[0].size(); i++)
        {
            // Subtract the current grid value from above total sum
            sum -= grid[0][i];

            // take max for robot 1 such that left min left behind robot 2 take min to choose maximum from left behind
            answer = min(answer, max(bottomSum, sum));

            // Update bottom sum by adding bottom value
            bottomSum += grid[1][i];
        }
        return answer;
    }
};