class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        int n = s.size();
        if (k > n)
            return false;
        if (k == n)
            return true;

        unordered_map<char, int> freqArr;
        for (int i = 0; i < n; i++)
            freqArr[s[i]]++;

        // How many are the Odd Freq
        int count = 0;
        auto it = freqArr.begin();
        for (auto it = freqArr.begin(); it != freqArr.end(); it++)
        {
            if (it->second % 2 != 0)
                count++;
        }

        return count <= k;
    }
};