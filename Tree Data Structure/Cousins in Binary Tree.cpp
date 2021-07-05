//Method - 1
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A, int B) {
    
    queue<pair<int,pair<TreeNode*,TreeNode*>>> q;
    
    unordered_map<int,pair<TreeNode*,int>> mymap;
    
    q.push({0,{A,NULL}});
    
    while(!q.empty()){
        
        int currd = q.front().first;
        TreeNode* par = q.front().second.second;
        TreeNode* curr = q.front().second.first;
        
        mymap[curr->val] = {par,currd};
        
        q.pop();
        
        if(curr -> left != NULL){
            q.push({currd+1,{curr->left,curr}});
        }
        
        if(curr ->right != NULL){
            q.push({currd+1,{curr->right,curr}});
        }
    }
    
    int reqd = mymap[B].second;
    TreeNode* reqpar = mymap[B].first;
    
    unordered_map<int,pair<TreeNode*,int>> :: iterator it;
    
    vector<int> res;
    
    for(it = mymap.begin(); it != mymap.end(); it++){
        
        if(it->first == B){
            continue;
        }
        
        if(it->second.second == reqd && it->second.first != reqpar){
            res.push_back(it->first);
        }
    }
    return res;
}

//Method - 2
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A, int B) {

    queue<pair<int,pair<TreeNode*,TreeNode*>>> q;

    unordered_map<int,vector<pair<TreeNode*,int>>> myumap;

    q.push({0,{A,NULL}});

    int reqd;
    TreeNode* reqpar;

    while(!q.empty()){

        int currd = q.front().first;
        TreeNode* curr = q.front().second.first;
        TreeNode* par = q.front().second.second;

        if(curr -> val == B){
            reqd = currd;
            reqpar = par;
        }

        myumap[currd].push_back({par,curr->val});

        q.pop();

        if(curr -> left != NULL){
            q.push({currd+1,{curr->left,curr}});
        }

        if(curr -> right != NULL){
            q.push({currd+1,{curr->right,curr}});
        }
    }

    vector<pair<TreeNode*,int>> v = myumap[reqd];

    vector<int> res;

    for(auto x: v){
        if(x.first != reqpar){
            res.push_back(x.second);
        }
    }
    return res;
}
