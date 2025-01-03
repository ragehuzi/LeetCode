class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        long long int totalSum = 0;
        for (auto i : nums)
            totalSum += i;

        long long prefixSum = 0;

        int counter = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            prefixSum += nums[i];
            if (prefixSum >= (totalSum - prefixSum))
                counter++;
        }
        return counter;
    }
};