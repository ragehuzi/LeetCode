class Solution
{
public:
    void reverseArr(vector<int> &nums)
    {
        int i = 0;
        int j = nums.size() - 1;

        while (i < j)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    vector<int> getBinary(int num, int length = 32)
    {
        vector<int> result(length, 0);
        int index = length - 1;

        while (num > 0 && index >= 0)
        {
            result[index] = num % 2;
            num /= 2;
            index--;
        }

        return result;
    }

    int countOnes(vector<int> nums)
    {
        int count = 0;
        for (auto i : nums)
        {
            if (i == 1)
                count++;
        }
        return count;
    }

    int getDecimal(vector<int> nums)
    {
        long long int ans = 0;
        long long int currentPower = 1;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] == 1)
            {
                ans += currentPower;
            }
            currentPower *= 2;
        }

        return ans;
    }

    int minimizeXor(int num1, int num2)
    {
        vector<int> num1Bin = getBinary(num1);
        vector<int> num2Bin = getBinary(num2);

        vector<int> x(num1Bin.size(), 0);
        int minOnes = countOnes(num2Bin);

        int i = 0, j = 0;
        while (j < minOnes && i < num1Bin.size())
        {
            if (num1Bin[i] == 1)
            {
                x[i] = 1;
                j++;
            }

            i++;
        }

        i = num1Bin.size() - 1;
        while (j < minOnes && i >= 0)
        {
            if (x[i] == 0) // Only set bits that are 0
            {
                x[i] = 1;
                j++;
            }
            i--;
        }

        return getDecimal(x);
    }
};