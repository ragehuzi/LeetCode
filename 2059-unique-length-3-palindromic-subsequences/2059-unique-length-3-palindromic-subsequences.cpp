class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        int count = 0;

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            int start = -1;
            int end = -1;

            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == ch && start == -1)
                {
                    start = i;
                    end = i;
                }
                else if (s[i] == ch)
                {
                    end = i;
                }
            }

            // Skip this because not forming the palindrome
            if (start == end)
                continue;

            // Here we store the elements in between the start and end of tha Character
            unordered_set<char> MiddleChar;
            for (int i = start + 1; i < end; i++)
            {
                MiddleChar.insert(s[i]);
            }

            count += MiddleChar.size();
        }
        return count;
    }
};