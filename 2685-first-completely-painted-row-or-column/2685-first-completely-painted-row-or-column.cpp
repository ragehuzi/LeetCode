class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        // First we store the row and col into HashTable
        unordered_map<int, pair<int, int>> freq; // num , row , col
        vector<int> row(mat.size(), 0);
        vector<int> col(mat[0].size(), 0);

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                freq[mat[i][j]] = {i, j};
            }
        }

        // now we take elements from the arr and mark into the matrix and check whether it forms valid row or col
        for (int i = 0; i < arr.size(); i++)
        {
            int r = freq[arr[i]].first;  // Row index
            int c = freq[arr[i]].second; // Column index

            row[r]++; // Increment count for the row
            col[c]++; // Increment count for the column

            // Check if the row or column is complete
            if (row[r] == mat[0].size() || col[c] == mat.size())
                return i;
        }
        return -1;
    }
};