/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    
    map<int,vector<int>> m;
    map<TreeNode*,int> depth;
    
    depth[A] = 0;
    
    queue<TreeNode*> q;
    q.push(A);
    
    while(!q.empty()){
        
        TreeNode* temp = q.front();
        m[depth[temp]].push_back(temp -> val);
        q.pop();
        
        if(temp -> left != NULL){
            q.push(temp -> left);
            depth[temp -> left] = depth[temp] + 1;
        }
        if(temp -> right  != NULL){
            q.push(temp -> right);
            depth[temp -> right] = depth[temp] + 1;
        }
        
    }
    
    vector<vector<int>> res;
    
    map<int,vector<int>> :: iterator it;
    
    for(it = m.begin(); it!=m.end(); it++){
            res.push_back(m[it->first]);
    }
    return res;
}
