#include <iostream>                   
#include <queue>                     
using namespace std;

//Creating structure of Node of a tree
class Node{
    public:
        int data;
        Node*left;
        Node*right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }   
};

//Function to insert data in a Binary Search Tree
Node * insert_in_BST(Node*root,int data){

    if(root==NULL){
        Node*new_node=new Node(data);
        root=new_node;
        return root;
    }

    if(data>root->data){root->right=insert_in_BST(root->right,data);}

    else if(data<root->data){root->left=insert_in_BST(root->left,data);}

    else{return root;}

    return root;
}

//Function to print a tree using Level Order Traversal
void level_order_traversal(Node*root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node*temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){q.push(NULL);};}

        else{
            cout<<temp->data<<" ";
            if(temp->left){q.push(temp->left);}
            if(temp->right){q.push(temp->right);}
        }
    }
}

//Function to get min value node in a Binary Search Tree
Node* min_value_node(Node* node)
{
    Node* current = node;

    while (current && current->left != NULL)
        current = current->left;
    return current;
}

//Function to delete a node in Binary Search Tree
Node* delete_node(Node* root, int key)
{
    if (root == NULL)
        return root;
  
    if (key < root->data)
        root->left = delete_node(root->left, key);
  
    else if (key > root->data)
        root->right = delete_node(root->right, key);

    else {
        if (root->left==NULL and root->right==NULL)
            return NULL;
        
        else if (root->left == NULL) {
             Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
             Node* temp = root->left;
            free(root);
            return temp;
        }
 
        Node* temp = min_value_node(root->right);
        root->data= temp->data;
        root->right = delete_node(root->right, temp->data);

    }
    return root;
}

//Function to print an array
void pfun(int arr[],int n){
    for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
    }
}

int main()
{
    //Taking number of element in array as input
    int n;
    cout<<"\nEnter number elements in the ARRAY to form BST:";cin>>n;
    int arr[n];
    cout<<"\nEnter elements of the array to form BST:";
    //Taking elements of array as input
    for(int i=0;i<n;i++){cin>>arr[i];}
    //printing the array