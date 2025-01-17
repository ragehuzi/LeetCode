class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {
        int ans = 0;
        for(auto i : derived)
        ans ^= i;

        return ans == 0 ? true : false;
    }
};