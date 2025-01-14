class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        unordered_set<int> setB;
        vector<int> result;

        for (int i = 0; i < A.size(); i++)
        {
            int count = 0;
            setB.insert(B[i]);
            for (int j = 0; j <= i; j++)
            {
                if (setB.find(A[j]) != setB.end())
                {
                    count++;
                }
            }
            result.push_back(count);
        }
        return result;
    }
};