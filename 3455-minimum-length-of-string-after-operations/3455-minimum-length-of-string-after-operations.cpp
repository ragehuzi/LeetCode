class Solution
{
public:
    int minimumLength(string s)
    {
        vector<stack<int>> freqArr(26); // for 26 character
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '-')
                continue;

            freqArr[s[i] - 'a'].push(i);

            if (freqArr[s[i] - 'a'].size() == 3)
            {
                int start, mid, end;
                end = freqArr[s[i] - 'a'].top();
                freqArr[s[i] - 'a'].pop();
                mid = freqArr[s[i] - 'a'].top();
                freqArr[s[i] - 'a'].pop();
                start = freqArr[s[i] - 'a'].top();
                freqArr[s[i] - 'a'].pop();

                s[start] = '-';
                s[end] = '-';
                freqArr[s[mid] - 'a'].push(mid);
            }
        }
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '-')
                continue;

            count++;
        }
        return count;
    }
};