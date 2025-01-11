

class AVLNode {
public:
    int val;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode() : val(0), height(1), left(nullptr), right(nullptr) {}
    AVLNode(int x) : val(x), height(1), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int getHeight(AVLNode* root) {
        if (root == nullptr)
            return 0;
        return root->height;
    }

    int getBalanceFactor(AVLNode* root) {
        return getHeight(root->left) - getHeight(root->right);
    }

    void rotateRight(AVLNode*& Y) {
        AVLNode* X = Y->left;
        AVLNode* T2 = X->right;

        // Perform rotation
        X->right = Y;
        Y->left = T2;

        // Update heights
        Y->height = 1 + max(getHeight(Y->left), getHeight(Y->right));
        X->height = 1 + max(getHeight(X->left), getHeight(X->right));

        Y = X;
    }

    void rotateLeft(AVLNode*& X) {
        AVLNode* Y = X->right;
        AVLNode* T2 = Y->left;

        // Perform rotation
        Y->left = X;
        X->right = T2;

        // Update heights
        X->height = 1 + max(getHeight(X->left), getHeight(X->right));
        Y->height = 1 + max(getHeight(Y->left), getHeight(Y->right));

        X = Y;
    }

    void balanceTree(AVLNode*& root) {
        int balance = getBalanceFactor(root);

        if (balance > 1) {
            if (getBalanceFactor(root->left) >= 0) {
                rotateRight(root); // Left-Left Case
            } else {
                rotateLeft(root->left); // Left-Right Case
                rotateRight(root);
            }
        } else if (balance < -1) {
            if (getBalanceFactor(root->right) <= 0) {
                rotateLeft(root); // Right-Right Case
            } else {
                rotateRight(root->right); // Right-Left Case
                rotateLeft(root);
            }
        }
    }

    void addElement(AVLNode*& root, int x) {
        AVLNode* newNode = new AVLNode(x);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        if (x < root->val)
            addElement(root->left, x);
        else if (x > root->val)
            addElement(root->right, x);

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        balanceTree(root);
    }

    void inorderTraversal(TreeNode* root, vector<int>& sortedArr) {
        if (root == nullptr)
            return;

        inorderTraversal(root->left, sortedArr);
        sortedArr.push_back(root->val);
        inorderTraversal(root->right, sortedArr);
    }

    TreeNode* convertAVLToTreeNode(AVLNode* root) {
        if (root == nullptr)
            return nullptr;

        TreeNode* newRoot = new TreeNode(root->val);
        newRoot->left = convertAVLToTreeNode(root->left);
        newRoot->right = convertAVLToTreeNode(root->right);

        return newRoot;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;

        // Perform an inorder traversal to get a sorted array
        inorderTraversal(root, nums);
        root = nullptr; // Clear the original BST

        // Build the AVL tree from the sorted array
        AVLNode* avlRoot = nullptr;
        for (auto i : nums)
            addElement(avlRoot, i);

        // Convert the AVL tree to a TreeNode tree
        return convertAVLToTreeNode(avlRoot);
    }
};
