class Solution
{
public:
    bool canBeValid(string s, string locked)
    {
        int n = s.size();
        if (n % 2 != 0)
            return false;

        stack<int> openLockedBracket; // store all locked open bracket
        stack<int> unlockedBracket;   // store unlock bracket needed to balance the lock ones

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' && locked[i] == '1')
            {
                openLockedBracket.push(i);
            }
            else if (s[i] == ')' && locked[i] == '1')
            {
                // first try to balance with locked ones
                if (!openLockedBracket.empty())
                {
                    openLockedBracket.pop();
                }
                else if (!unlockedBracket.empty())
                {
                    unlockedBracket.pop();
                }
                else // means balance hi na ho raha na hi locked se na hi unlocked available he balance ke lia
                {
                    return false;
                }
            }
            else // locked ni he to bs unlocked wale me daldo just
            {
                unlockedBracket.push(i);
            }
        }
        while (!openLockedBracket.empty() && !unlockedBracket.empty() && openLockedBracket.top() < unlockedBracket.top())
        {
            // means ke unlocked wala age hona chahiye open wala se jabhi to close karega wrna kese hi hoga
                openLockedBracket.pop();
                unlockedBracket.pop();
        }

        return (openLockedBracket.empty()) ? true : false;
    }
};