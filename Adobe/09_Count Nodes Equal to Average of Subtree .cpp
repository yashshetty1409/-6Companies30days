class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        pot(root,count);
        return count;
    }
    
    vector<int> pot(TreeNode* root, int &count){
        if(root == NULL) return {0,0};
        
        vector<int> av1 = pot(root->left,count);
        vector<int> av2 = pot(root->right,count);
        
        if((av1[0]+av2[0]+root->val)/(av1[1]+av2[1]+1) == root->val)
            count++;
        
        return {av1[0]+av2[0]+root->val,av1[1]+av2[1]+1};
    }
};