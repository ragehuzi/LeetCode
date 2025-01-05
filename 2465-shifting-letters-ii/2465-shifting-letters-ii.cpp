class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        int n = shifts.size();
        vector<int> shift_times(s.length() + 1, 0);

        // Process each shift operation
        for (int i = 0; i < n; i++)
        {
            int start = shifts[i][0], end = shifts[i][1], direction = shifts[i][2];

            if (direction == 0) // backward
            {
                shift_times[start] -= 1;
                shift_times[end + 1] += 1;
            }
            else if (direction == 1) // forward
            {
                shift_times[start] += 1;
                shift_times[end + 1] -= 1;
            }
        }

        // Calculate prefix sums to accumulate the shifts
        for (int i = 1; i < shift_times.size(); i++)
        {
            shift_times[i] += shift_times[i - 1];
        }

        // Apply shifts to the string
        for (int i = 0; i < s.length(); i++)
        {
            int shift = (s[i] - 'a' + shift_times[i]) % 26; // Calculate shifted index
            if (shift < 0) // Handle negative shifts to wrap around properly
                shift += 26;
            s[i] = shift + 'a'; // Convert back to character
        }

        return s;
    }
};
