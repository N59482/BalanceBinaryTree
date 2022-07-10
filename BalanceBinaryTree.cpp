class Solution 
    {    
        public:
        vector<int> TreeValues;// данные из дерева
        void TreeToVector(TreeNode* root) 
            {
                while(root != nullptr)
                    {
                        TreeValues.push_back(root->val);
                        TreeToVector(root->left);
                        TreeToVector(root->right);
                        return;
                    };
            };
        TreeNode* VectorToTree(int l, int r)
            {
                if(l > r) return nullptr;
                int mid = (l+r)/2;
                TreeNode * root = new TreeNode(); 
                root->val = TreeValues[mid];
                root->left = VectorToTree(l, (mid - 1));
                root->right = VectorToTree((mid+1), r);
                return root;
            };
        TreeNode* balanceBST(TreeNode* root) 
        {
            TreeToVector(root);
            return VectorToTree(0, TreeValues.size()-1); 
        }
    };