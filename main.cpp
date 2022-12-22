//
//  main.cpp
//  binary_search_tree
//
//  Created by Ragupathi on 05/09/2022.
//

#include <iostream>
#include <queue>
#include <stack>

using namespace std;
//BINARY SEARCH TREE:
//insertion, preorder, postorder, inorder, levelorder, spiralorder
//deletion, searching

class node {
private:
    int data;
    node *left;
    node *right;
public:
    node *root = NULL;
    node * newnode(int data){
        node * newNode = new node;
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    node * insert(node * root, int data){
        if(root == NULL){
            root = newnode(data);
        }
        
        if(root->data < data){
            root->right = insert(root->right, data);
        }
        else if(root->data > data){
            root->left = insert(root->left, data);
        }
        
        return root;
    }
    void inorder(node *root){
        if(root != NULL){
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
    void preorder(node *root){
        if(root != NULL){
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    void postorder(node *root){
        if(root != NULL){
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }
    
    int height(node *root){
        if (root == NULL){
            return 0;
        }
        else{
            int leftHeight = height(root->left);
            int rightHeight = height(root->right);
            if(leftHeight > rightHeight){
                return (leftHeight+1);
            }
            else{
                return (rightHeight+1);
            }
        }
    }
    //print level order traversal using queues
    void levelorder(node * root){
        if(root == NULL){
            return;
        }
        
        queue <node *> q;
        
        q.push(root);
        
        while(q.empty() == false){
            node * temp = q.front();
            cout << temp->data << " ";
            q.pop();
            
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
        
    }
    //spiral order traversal using stack
    /*void spiralorder_stack(node *root){
        stack <node *> s1;
        stack <node *> s2;
        
        s1.push(root);
        while(!s1.empty() || !s2.empty()){
            while(!s1.empty()){
                //pop the parent
                node *temp = s1.top();
                s1.pop();
                cout << temp->data << " ";
                
                
                //push the children
                if(temp->right){
                    s2.push(temp->right);
                }
                if(temp->left){
                    s2.push(temp->left);
                }
            }
            
            while(!s2.empty()){
                node *temp = s2.top();
                s2.pop();
                cout << temp->data << " ";
                
                //push the children
                if(temp->right){
                    s1.push(temp->right);
                }
                if(temp->left){
                    s1.push(temp->left);
                }
            }
            
        }
    }*/
    // spiral order traveral using doubly ended queue
  /* void spiralorder_deque(node *root){
        deque <node *> dq;
        dq.push_back(root);
        
    }
    */
    //find inorder successor for a given node:
    
    
    //deletion
    // no child
    // one child
    // two or more child
    node * deletion (node * root, int data){
        if(root == NULL){
            return root;
        }
        //locate the deleting node
        else if(root->data < data){
            root->left = deletion(root->left, data);
        }
        else if(root->data > data){
            root->right = deletion(root->right, data);
        }
        //found the node to be deleted
        else if(root->data == data){
            //if this node has no child
            if(root->left == NULL && root->right == NULL){
                node *temp = root;
                delete temp;
                temp = NULL;
                return root;
            }
            //if this temp has one right child
            else if(root->left == NULL){
                node *temp = root;
                root = root->right;
                delete temp;
                return root;
            }
            else if(root->right == NULL){
                node *temp = root;
                root = root->left;
                delete temp;
                return root;
            }
            
            else{
                
            }
            
            //if this temp has one left child
                
            //
        }
    }
    
    
    
    
    void search(node *root, int data){
        node *temp = root;
        if(root == 0){
            cout << "\n" << data << " not found" << endl;
        }
        else if(root->data == data){
            cout << "found" << endl;
        }
        else{
            if(temp->data < data){
                search(temp->right, data);
            }
            else{
                search(temp->left, data);
            }
            
        }
    }
    
    //delete root
    
    //search the element and delete
    
};

int main() {
    node bst;
    int choice = 7, element, option;
    cout << "\nthis program is to implement the binary search tree data structure\n";
    while(choice != 6){
        cout << "\nTo insert: press 1\nTo display: press 2\nTo delete: press 3\nTo search: press 4\nTo display the height: press 5\nTo exit: press 6\n";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "\nFor insertion: please enter the element: ";
                cin >> element;
                bst.root = bst.insert(bst.root, element);
                break;
                
            case 2:
                cout << "\nTo display: please choose your choice of traversal:\ninorder: press 1\npreorder: press 2\npostorder: press 3\nlevelorder: press 4\nspiral order: press 5\nfor all traversals: press 6\n";
                cin >> option;
                if(option == 1){
                    cout << "\ninorder : ";
                    bst.inorder(bst.root);
                }
                else if(option == 2){
                    cout << "\npreorder : ";
                    bst.preorder(bst.root);
                }
                else if(option == 3){
                    cout << "\npostorder : ";
                    bst.postorder(bst.root);
                }
                else if(option == 4){
                    cout << "\nlevelorder : ";
                    bst.levelorder(bst.root);
                }
                else if(option == 5){
                    cout << "\nspiralorder using stack : ";
                    //bst.spiralorder_stack(bst.root);
                    cout << "\nspiralorder using deque : ";
                }
                else if(option == 6){
                    cout << "\ninorder : ";
                    bst.inorder(bst.root);
                    cout << "\npreorder : ";
                    bst.preorder(bst.root);
                    cout << "\npostorder : ";
                    bst.postorder(bst.root);
                    cout << "\nlevelorder : ";
                    bst.levelorder(bst.root);
                    cout << "\nspiralorder using stack : ";
                    //bst.spiralorder_stack(bst.root);
                }
                else{
                    cout << "\nplease choose a valid option\n";
                }
                break;
            case 3:
                cout << "\nFor deletion:\ndelete root: press 1\nsearch and delete: press 2\n";
                cin >> option;
                if(option == 1){
                    bst.deletion(bst.root);
                }
                else if(option == 2){
                    cout << "\nplease provide the element: ";
                    cin >> element;
                }
                
                break;
                
            case 4:
                cout << "\nFor searching, please provide the element: ";
                cin >> element;
                bst.search(bst.root, element);
                break;
                
            case 5:
                cout << "\nthe current height of the tree is :";
                bst.height(bst.root);
                break;
                
            case 6:
                cout << "\nyou've successfully exited the program :)\n";
                break;
                
            default:
                cout << "\nplease enter a valid choice\n";
                break;
        }
    }
    
    
    return 0;
}
/* bst.root = bst.insert(bst.root, 5);
bst.root = bst.insert(bst.root, 6);
bst.root = bst.insert(bst.root, 2);
bst.root = bst.insert(bst.root, 3);
bst.root = bst.insert(bst.root, 4);
bst.root = bst.insert(bst.root, 1);
cout << "\ninorder : ";
bst.inorder(bst.root);
cout << "\npreorder : ";
bst.preorder(bst.root);
cout << "\npostorder : ";
bst.postorder(bst.root);
cout << "\nheight : ";
cout << bst.height(bst.root);
cout << "\nlevelorder : ";
bst.levelorder(bst.root);
bst.search(bst.root, 7);*/
