#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class BinaryTreeNodes{
public:
    T data;
    BinaryTreeNodes* left;
    BinaryTreeNodes* right;
    BinaryTreeNodes(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BinaryTreeNodes(){
        delete left;
        delete right;
    }
};
void printBinaryTree(BinaryTreeNodes<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<" L->" <<root->left->data;
    }
    if(root->right!=NULL){
        cout<<" R->"<<root->right->data;
    }
    cout<<endl;
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}
BinaryTreeNodes<int>* takingInput(){
    int rootData;
    cout<<"enter data: "<<endl;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNodes<int>* root=new BinaryTreeNodes<int>(rootData);
    BinaryTreeNodes<int>* leftChild=takingInput();
    BinaryTreeNodes<int>* rightChild=takingInput();
    root->left=leftChild;
    root->right=rightChild;
    return root;
}
int main(){
    /*BinaryTreeNodes<int>* root=new BinaryTreeNodes<int>(10);
    BinaryTreeNodes<int>* node1=new BinaryTreeNodes<int>(20);
    BinaryTreeNodes<int>* node2=new BinaryTreeNodes<int>(30);
    root->left=node1;
    root->right=node2;*/
    BinaryTreeNodes<int>* root=takingInput();
    printBinaryTree(root);
    delete root;
}
