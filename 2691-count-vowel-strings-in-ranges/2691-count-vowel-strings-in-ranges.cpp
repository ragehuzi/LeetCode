class Solution
{
public:
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        vector<bool> vowels(words.size(), false);

        for (int i = 0; i < words.size(); i++)
        {
            if (words[i][0] == 'a' || words[i][0] == 'e' || words[i][0] == 'i' || words[i][0] == 'o' || words[i][0] == 'u')
            {
                vowels[i] = true;
            }
            else
            {
                continue;
            }
            if (words[i][words[i].size() - 1] == 'a' || words[i][words[i].size() - 1] == 'e' || words[i][words[i].size() - 1] == 'i' || words[i][words[i].size() - 1] == 'o' || words[i][words[i].size() - 1] == 'u')
            {
                vowels[i] = true;
                continue;
            }
            vowels[i] = false;
        }

        // Now use the prefix sum Technique
        vector<int> prefixSum(vowels.size() + 1, 0);
        for (int i = 0; i < vowels.size(); i++)
        {
            prefixSum[i + 1] = vowels[i] + prefixSum[i];
        }

        // Now find the resultant using queries
        vector<int> result;
        for (int i = 0; i < queries.size(); i++)
        {
            result.push_back(prefixSum[queries[i][1] + 1] - prefixSum[queries[i][0]]);
        }
        return result;
    }
};