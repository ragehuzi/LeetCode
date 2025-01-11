class AVLNode
{
public:
    int val;
    int height;
    AVLNode *left;
    AVLNode *right;

    AVLNode() : val(0), height(1), left(nullptr), right(nullptr) {}
    AVLNode(int x) : val(x), height(1), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int getHeight(AVLNode *root)
    {
        if (root == nullptr)
            return 0;

        return root->height;
    }

    int getBalanceFactor(AVLNode *root)
    {
        return (getHeight(root->left) - getHeight(root->right));
    }

    void rotateRight(AVLNode *&Y)
    {
        AVLNode *X = Y->left;
        AVLNode *T2 = X->right;

        // Rotation
        X->right = Y;
        Y->left = T2;

        Y->height = 1 + max(getHeight(Y->left), getHeight(Y->right));
        X->height = 1 + max(getHeight(X->left), getHeight(X->right));

        Y = X;
    }

    void rotateLeft(AVLNode *&X)
    {
        AVLNode *Y = X->right;
        AVLNode *T2 = Y->left;

        Y->left = X;
        X->right = T2;

        X->height = 1 + max(getHeight(X->left), getHeight(X->right));
        Y->height = 1 + max(getHeight(Y->left), getHeight(Y->right));

        X = Y;
    }

    void balanceTree(AVLNode *&root)
    {
        int balance = getBalanceFactor(root);

        if (balance > 1)
        {
            // Check if it is the Left-Left Case
            if (getBalanceFactor(root->left) >= 0)
            {
                rotateRight(root);
            }
            else
            {
                // Left-right Case
                rotateLeft(root->left);
                rotateRight(root);
            }
        }
        else if (balance < -1)
        { // Right-Right Case
            if (getBalanceFactor(root->right) <= 0)
            {
                rotateLeft(root);
            }
            else
            {
                // Right - Left Case
                rotateRight(root->left);
                rotateLeft(root);
            }
        }
    }

    void addElement(AVLNode *&root, int x)
    {
        AVLNode *newNode = new AVLNode(x);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        if (x < root->val)
            addElement(root->left, x);

        if (x > root->val)
            addElement(root->right, x);

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        balanceTree(root);
    }

    void addBST(TreeNode *&root, int x)
    {
        TreeNode *newNode = new TreeNode(x);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }
        if (root->val >= x)
            addBST(root->right, x);

        if (root->val < x)
            addBST(root->right, x);
    }

    void inorderTraversal(TreeNode *root, vector<int> &sortedArr)
    {
        if (root == nullptr)
            return;

        inorderTraversal(root->left, sortedArr);
        sortedArr.push_back(root->val);
        inorderTraversal(root->right, sortedArr);
    }

    TreeNode *convertAVLToTreeNode(AVLNode *root)
    {
        if (root == nullptr)
            return nullptr;

        TreeNode *newRoot = new TreeNode(root->val);
        newRoot->left = convertAVLToTreeNode(root->left);
        newRoot->right = convertAVLToTreeNode(root->right);

        return newRoot;
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> nums;

        inorderTraversal(root, nums);
        root = nullptr;

        AVLNode *avlroot = nullptr;
        for (auto i : nums)
            addElement(avlroot, i);

        return convertAVLToTreeNode(avlroot);
    }
};