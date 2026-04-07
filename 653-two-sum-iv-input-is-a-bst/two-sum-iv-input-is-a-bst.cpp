class BSTIterator {
    stack<TreeNode*> myStack;
    bool reverse;

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext() {
        return !myStack.empty();
    }

    int next() {
        TreeNode* tmpNode = myStack.top();
        myStack.pop();

        if (!reverse)
            pushAll(tmpNode->right);
        else
            pushAll(tmpNode->left);

        return tmpNode->val;  // change to data if needed
    }

private:
    void pushAll(TreeNode* node) {
        while (node != NULL) {
            myStack.push(node);

            if (reverse)
                node = node->right;
            else
                node = node->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator l(root, false); // normal inorder
        BSTIterator r(root, true);  // reverse inorder

        int i = l.next();
        int j = r.next();

        while (i < j) {
            if (i + j == k) return true;
            else if (i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};