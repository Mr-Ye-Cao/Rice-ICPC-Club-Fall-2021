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
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int> > res;
        
        if(root==nullptr)
            return res;
    
    // 0 goleft -1 go right +1 BFS so that deeper node put later
    // first node represent the magnitude, second # added
        int order=0;
        TreeNode* cr;
        vector<tuple<int,int,int> > tra;
        queue<pair<int,TreeNode*> > bf;
  
        // base case
        cr=root;
        bf.push(make_pair(0,cr));
        
        while(!bf.empty()){
            int mag=bf.front().first;
            TreeNode* child=bf.front().second;
            tra.push_back(make_tuple(mag,order,child->val));
            
            order++;
            bf.pop();
            
            if(child->left!=nullptr){
                bf.push(make_pair(mag-1,child->left));
            }
            if(child->right!=nullptr){
                bf.push(make_pair(mag+1,child->right));
            }
        }
        
        std::sort(tra.begin(),tra.end());
        
        map<int,vector<int> > pres;
        
        for(int i=0;i<tra.size();i++){
            int m,o,v;
            tie(m,o,v)=tra[i];
            
            pres[m].push_back(v);
        }
        
        for(auto p:pres){
            res.push_back(p.second);
        }
        
        return res;
    }
};