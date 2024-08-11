/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    TreeNode *findLCA(TreeNode *curr, int startVal, int destVal)
    {
        if (!curr)
            return NULL;
        if (curr->val == startVal || curr->val == destVal)
            return curr;
        TreeNode *left = findLCA(curr->left, startVal, destVal);
        TreeNode *right = findLCA(curr->right, startVal, destVal);
        if (left && right)
            return curr;
        if (right && !left)
            return right;
        return left;
    }

private:
    bool findDest(TreeNode *node, int dest, string path)
    {
        if (node->val == dest)
            return true;
        if (findDest(node->left, dest, path))
        {
        }
        if (findDesst(node->right, dest, path))
        {
        }

        return false;
    }

public:
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        TreeNode *LCA = findLCA(root, startValue, destValue);
        string ans = "";
        if (LCA->val == startValue)
        {
            findDest(LCA, destValue, ans);
        }
        else if (LCA->val == destValue)
        {
        }
        return ans;
    }
};