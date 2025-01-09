class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int found = 0;
        bool find;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < pref.size(); j++)
            {
                if(words[i][j] == pref[j])
                {
                     find = true;
                } else {
                    find = false;
                    break;
                }
            }

            (find == true) ? found++ : found ;   
        }
        return found;
    }
};