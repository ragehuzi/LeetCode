class Solution
{
public:
    int countOnes(string &str)
    {
        int ones = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '1')
                ones++;
        }
        return ones;
    }

    int countZeros(string &str)
    {
        int zeros = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '0')
                zeros++;
        }
        return zeros;
    }

    int maxScore(string s)
    {
        int maximum = 0;

        for (int j = 0; j < s.size() - 1; j++)
        {
            string subString1;
            string subString2;
            for (int i = 0; i < s.size(); i++)
            {
                if (i <= j)
                {
                    subString1.push_back(s[i]);
                }
                else
                {
                    subString2.push_back(s[i]);
                }
            }

            maximum = max(maximum, countZeros(subString1) + countOnes(subString2));
        }
        return maximum;
    }
};