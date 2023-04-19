#include <iostream>
using namespace std;
struct TreeNode
{
    int info;
    struct TreeNode *left,*right;
};
struct TreeNode* create()
{
    int data;
    struct TreeNode* tree; // Dynamically allocating memory for the tree-node
    tree=new TreeNode;
    cout<<"\nEnter data to be inserted "<<" or type -1 for no insertion : ";
    cin>>data;
    if (data==-1)
    {
        return 0;
    }
    tree->info=data;
    cout<<"Enter the left child of: "<<data;
    tree->left=create();
    cout<<"Enter the right child of: "<<data;
    tree->right=create();
    return tree;
    };
    void inorder(struct TreeNode* root){
        if (root=NULL)
        {
            return;
        }
        // Recursively call for the left and right subtree.
        cout<<root->info<<" ";
        inorder(root->left);
        inorder(root->right);
    }
class Solution {
public:
    int countNodes(TreeNode* root) {
        
        cout<<root->info<<endl;
    }
};
int main(){
    struct TreeNode* root=NULL;
    root=create();
    inorder(root);
    Solution s;
    s.countNodes(root);
    return 0;
}