class Node
{
public:
    int value;
    int height;
    Node *left = nullptr;
    Node *right = nullptr;

    Node() : value(0), height(1), left(nullptr), right(nullptr) {}
    Node(int val) : value(val), height(1), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<int> nums;

    int getHeight(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return node->height;
    }

    int getBalanceFac(Node *root)
    {
        return getHeight(root->left) - getHeight(root->right);
    }

    void rotateRight(Node *&Y)
    {
        Node *X = Y->left;
        Node *T2 = X->right;

        X->right = Y;
        Y->left = T2;

        Y->height = 1 + max(getHeight(Y->left), getHeight(Y->right));
        X->height = 1 + max(getHeight(X->left), getHeight(X->right));

        Y = X;
    }

    void rotateLeft(Node *&X)
    {
        Node *Y = X->right;
        Node *T2 = Y->left;

        Y->left = X;
        X->right = T2;

        X->height = 1 + max(getHeight(X->left), getHeight(X->right));
        Y->height = 1 + max(getHeight(Y->left), getHeight(Y->right));

        X = Y;
    }

    void balanceTree(Node *&root)
    {
        if (root == nullptr)
            return;

        int balance = getBalanceFac(root);

        if (balance > 1)
        {
            if (getBalanceFac(root->left) >= 0)
            {
                rotateRight(root);
            }
            else
            {
                rotateLeft(root->left);
                rotateRight(root);
            }
        }
        else if (balance < -1)
        {
            if (getBalanceFac(root->right) <= 0)
            {
                rotateLeft(root);
            }
            else
            {
                rotateRight(root->right);
                rotateLeft(root);
            }
        }
    }

    void insertAVL(Node *&root, int x)
    {
        if (root == nullptr)
        {
            root = new Node(x);
            return;
        }

        if (x <= root->value)
            insertAVL(root->left, x);
        else
            insertAVL(root->right, x);

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        balanceTree(root);
    }

    Node *listToAVL(ListNode *head)
    {
        Node *AVLTree = nullptr;
        while (head != nullptr)
        {
            insertAVL(AVLTree, head->val);
            head = head->next;
        }
        return AVLTree;
    }

    void LevelOrderTraversal(Node *root)
    {
        queue<Node *> list;
        list.push(root);

        while (!list.empty())
        {
            Node *temp = list.front();
            list.pop();
            nums.push_back(temp->value);
            if (temp->left != nullptr)
            {
                list.push(temp->left);
            }
            if (temp->right != nullptr)
            {
                list.push(temp->right);
            }
        }
    }

    void insertBST(TreeNode *&root, int x)
    {
        if (root == nullptr)
        {
            root = new TreeNode(x);
            return;
        }

        if (x <= root->val)
            insertBST(root->left, x);
        else
            insertBST(root->right, x);
    }

    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        Node *AVLTree = listToAVL(head);
        LevelOrderTraversal(AVLTree);

        TreeNode *BST = nullptr;
        for (int i : nums)
            insertBST(BST, i);

        return BST;
    }
};