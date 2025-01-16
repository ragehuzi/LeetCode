class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int answer = 0;
        if (nums1.size() % 2 != 0) // Odd
        {
            for (auto i : nums2)
                answer ^= i;
        }

        if (nums2.size() % 2 != 0)
        {
            for (auto i : nums1)
                answer ^= i;
        }
        return answer;
    }
};