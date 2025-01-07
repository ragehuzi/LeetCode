class Solution
{
public:
    vector<int> buildPieTable(string s)
    {
        vector<int> table(s.size(), 0);
        int i = 1;      // Start with 1 bcz at 0 doesn't match with previous
        int lenght = 0; // Compare prefix(next substring) with the suffix(previous substring)

        while (i < s.size())
        {
            if (s[i] == s[lenght])
            {
                lenght++;
                table[i] = lenght;
                i++;
            }
            else
            {
                // Two cases if s.size() is not empty at back means previously character left so we shift it back
                if (lenght > 0)
                {
                    lenght = table[lenght - 1]; // Try the previous prefix sufix
                }
                else
                {
                    table[i] = 0; // bcz we are the start means so again compare and start with the zero
                    i++;
                }
            }
        }
        return table;
    }

    bool KMPSearch(string text, string pattern)
    {
        vector<int> pieTable = buildPieTable(pattern);
        int i = 0, j = 0;

        while (i < text.size())
        {
            if (text[i] == pattern[j])
            {
                i++;
                j++;
            }

            if (j == pattern.size()) // Full pattern matched
            {
                return true; // Reason for subtracting pattern.size() is bcz it i is matches till end
            }
            else if (i < text.size() && text[i] != pattern[j])
            {
                if (j != 0)
                {
                    j = pieTable[j - 1]; // Use LPS table to skip comparisons
                }
                else
                {
                    i++;
                }
            }
        }

        return false; // Pattern not found
    }
    vector<string> stringMatching(vector<string> &words)
    {
        set<string> duplicate;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words.size(); j++)
            {
                if (KMPSearch(words[i], words[j]) && i != j)
                {
                    duplicate.insert(words[j]);
                }
            }
        }

        vector<string> result;
        for (auto i : duplicate)
            result.push_back(i);

        return result;
    }
};