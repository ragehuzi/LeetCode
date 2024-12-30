class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> result;
        if (nums.empty() || k == 0)
            return result;

        map<int, int> frequency;
        for (auto i : nums)
            frequency[i]++;

        priority_queue<pair<int, int>> maxHeap;
        for (auto it : frequency)
            maxHeap.push({it.second, it.first});

        for (int i = 0; i < k; i++)
        {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};