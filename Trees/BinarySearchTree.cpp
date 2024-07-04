#include<bits/stdc++.h>
using namespace std ;
template <class var>
class binarySearchTree
{
    private :
        struct Node
        {
            var item ;
            Node *left ;
            Node *right ;
        };
        Node *root ;
        int numNodes ;
        void inOrder(Node *root)
        {
            if(root == NULL) return ;
            inOrder(root->left);
            cout << root->item  << " " ;
            inOrder(root -> right) ;
        }
        void preOrder(Node *root) 
        {
            if(root == NULL) return ;
            cout << root -> item <<" ";
            preOrder(root -> left) ;
            preOrder(root -> right) ;
        }
        void postOrder(Node *root) 
        {
            if(root == NULL) return ;
            preOrder(root -> left) ;
            preOrder(root -> right) ;
            cout << root -> item <<" ";
        }
        int countleaves(Node *root) 
        {
            if(root == NULL) return 0;
            else if(root -> left == NULL && root -> right ==NULL) return 1 ;
            else return countleaves(root -> left) + countleaves(root -> right) ;
        }   
        int height(Node *root)
        {
            if(root == NULL) return 0 ;
            else
            {
                return 1 + max(height(root->left),height(root -> right)) ;
            } 
        }
        void clear(Node *&root)
        {
            if(root != NULL) 
        {
            clear(root -> left) ;
            clear(root -> right) ;
            delete root ; 
            root = NULL;
        }
            }
    public :
        binarySearchTree()
        : root(NULL) , numNodes(0) 
        {}

        bool isEmpty() {
            return root == NULL ;
        }

        void insert(var item)
        {
            Node *cur , *prev , *newNode = new Node ;
            newNode -> left = newNode -> right = NULL ;
            newNode -> item = item ;
            if( root == NULL)
            {
                root = newNode ;
            }
            else{
                cur = root ;
                while(cur != NULL)
                {
                    prev = cur ;
                    if(cur -> item == item)
                    {
                        cout << "The element is already in the tree\n" ;
                        cout << "Duplicated elements doesnt allowed in the tree.\n";
                        cout << "------------------------------------------------------\n" ;
                        delete newNode ;
                        return ;
                    }
                    else if(cur -> item > item) cur = cur -> left ;
                    else cur = cur -> right ;
                }
                if(prev -> item > item) prev -> left = newNode ;
                else prev -> right = newNode ;
            }
            numNodes ++ ;
            cout << "New node added in the tree now the tree contains " <<numNodes <<" nodes\n";
            cout << "------------------------------------------------------\n" ;
        }

        void inOrderTraversal()
        {
            inOrder(this->root) ;
            cout << "\n------------------------------------------------------\n" ;
        }
        void preOrderTraversal()
        {
            preOrder(this->root) ;
            cout << "\n------------------------------------------------------\n" ;
        }
        void postOrderTraversal()
        {
            postOrder(this->root) ;
            cout << "\n------------------------------------------------------\n" ;
        }

        int countLeaves()
        {
            return countleaves(root) ;
        }

        int countNodes()
        {
            return numNodes ;
        }

        int treeHeight()
        {
            return height(root);
        }

        bool searchTree(var item)
        {
            Node *cur = root ;
            while(cur != NULL)
            {
                if(cur -> item == item) return true ;
                else if(cur -> item > item) cur = cur -> left ;
                else cur = cur -> right ;
            }
            return false ;
        }

        void clearTree()
        {
            clear(root) ;
        }
        ~binarySearchTree()
        {
            clear(root) ;
        }


        //TO DETERMINE THE NODE THAT CONTAINS THE ELEMENT THAT WILL BE DELETED........
        void removeElement(var item)
        {
            Node *cur = root , *prev;
            if(root == NULL)
            {
                cout << "The Tree is already empty \n" ;
                return ;
            }
            else if(cur -> item == item) { deleteFromTree(root); return ;}
            else if(cur -> item > item) cur = cur -> left ;
            else 
            { cur = cur -> right ;}
                while(cur != NULL)
                {
                    if(cur -> item == item) {deleteFromTree(cur); return ;}
                    else if(cur -> item < item) cur = cur -> right ;
                    else cur = cur -> left ;
                }
            cout << item <<" is not found in the tree..." ;
            }

            void deleteFromTree(Node *&p)
            {
                Node *cur , *prev ;
                if(p->left == NULL && p->right ==NULL)//HAVE NO CHILDREN
                    {delete p ; p = NULL ;}
                else if(p -> left == NULL) //HAVE ONE CHILD ON RIGHT
                {
                    cur = p ; 
                    p = p->right ;
                    delete p ;
                }
                else if(p -> right == NULL) //HAVE ONE CHILD ON LEFT
                {
                    cur = p ; 
                    p = p->left ;
                    delete p ;
                }
                else //NODE HAS TWO CHILDREN
                {
                    cur = p -> left ;
                    prev = NULL ;

                    while(cur -> right != NULL) 
                    {
                        prev = cur ;
                        cur = cur -> right ;
                    }

                    p -> item = cur -> item ;

                    if(prev == NULL) // cur -> right == NULL
                        p -> left = cur -> left ;
                    else{
                        prev->left = cur -> left ; 
                    }            // prev node bef cur not equal null 
                        
                        delete cur ;
                }
                numNodes--;
                cout << "Element is deleted ......!\n" ;
            }
            
        

};

int main()
{
    /*
            54
          /    \
        15      96
    */
    binarySearchTree<int> T ;
    T.insert(54);
    T.insert(96);
    T.insert(15);
    T.insert(54) ;
    T.insert(13);
    T.inOrderTraversal();
    T.preOrderTraversal();
    T.postOrderTraversal();
    T.removeElement(54) ;
    T.removeElement(96) ;
}