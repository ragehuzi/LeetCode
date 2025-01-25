class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end()); // Sort the array for grouping

        vector<vector<int>> group;
        unordered_map<int, int> record; //<nums, group> to keep track of group assignments
        vector<int> subGroup;

        subGroup.push_back(temp[0]); // Start the first group
        record[temp[0]] = 0;

        for (int i = 1, j = 0; i < temp.size(); i++)
        {
            if (temp[i] - temp[i - 1] <= limit) // Compare with the previous element
            {
                subGroup.push_back(temp[i]);
                record[temp[i]] = j;
            }
            else
            {
                group.push_back(subGroup); // Finish the current group
                subGroup.clear();          // Start a new group
                j++;
                subGroup.push_back(temp[i]);
                record[temp[i]] = j;
            }
        }
        group.push_back(subGroup); // Add the last group

        // Now placing the elements in lexicographical order
        for (int i = 0; i < nums.size(); i++)
        {
            int n = record[nums[i]];
            nums[i] = group[n].front();
            group[n].erase(group[n].begin()); // Remove front element
        }

        return nums;
    }
};