class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int nLeft = maxDepth(root->left);
        int nRight = maxDepth(root->right);
        return (nLeft > nRight) ? (nLeft+1) : (nRight+1);
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int num = 0;
        queue<TreeNode *> que;
        que.push(root);
        while(!que.empty()){
            int n = que.size();
            for(int i = 0;i < n;++i){
                TreeNode *cur = que.front();
                if(cur->left != NULL)
                    que.push(cur->left);
                if(cur->right != NULL)
                    que.push(cur->right);
                que.pop();
            }
            num++;
        }
        return num;
    }
};
