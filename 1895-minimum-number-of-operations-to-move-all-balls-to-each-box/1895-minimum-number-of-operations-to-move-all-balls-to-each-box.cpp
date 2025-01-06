class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        // LeftSum for to move ball at i index from left
        // rightSum for to move ball at i index from right
        vector<int> leftSum(boxes.size(), 0);
        vector<int> rightSum(boxes.size(), 0);

        int ballCount = boxes[0] - '0';
        for (int i = 1; i < leftSum.size(); i++)
        {
            leftSum[i] = leftSum[i - 1] + ballCount;

            if (boxes[i] == '1')
                ballCount++;
        }

        int j = boxes.size() - 1;
        ballCount = boxes[j] - '0';
        for (int i = boxes.size() - 2; i >= 0; i--, j--)
        {
            rightSum[i] = rightSum[i + 1] + ballCount;

            if (boxes[j - 1] == '1')
                ballCount++;
        }

        vector<int> result;
        for (int i = 0; i < boxes.size(); i++)
        {
            result.push_back(leftSum[i] + rightSum[i]);
        }
        return result;
    }
};