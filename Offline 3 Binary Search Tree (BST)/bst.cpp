#include <iostream>
using namespace std;

template <typename E>
class Node
{
    E item;
    Node * leftChild;
    Node * rightChild;

public:

    Node()
    {
        leftChild = rightChild = NULL ;
    }

    Node (E param, Node * l_param = NULL, Node *r_param = NULL)
    {
        item = param;
        leftChild = l_param;
        rightChild = r_param;
    }

    ~Node()
    {

    }

    void setItem(E param)
    {
        item = param;
    }

    E getItem()
    {
        return item;
    }

    Node * getLeftChild()
    {
        return leftChild;
    }
    Node * getRightChild()
    {
        return rightChild;
    }

    Node *setLeft(Node *node)
    {
        leftChild = (Node*) node;
    }
    Node *setRight (Node *node)
    {
        rightChild = (Node*) node;
    }

    bool isLeaf()
    {
        if(leftChild == NULL && rightChild == NULL)
            return true;
        else
            return false;
    }

    bool isInternalNode()
    {
        if((leftChild == NULL && rightChild != NULL) || (leftChild != NULL && rightChild == NULL) || (leftChild != NULL && rightChild!= NULL))
            return true;
        else
            return false;
    }


};


template <typename E>
class BST : public Node <E>
{
    Node <E> * root;
    int count;

    void clearHelper(Node <E>* node)
    {
        if(node == NULL) return;
        else
        {
            clearHelper(node->getLeftChild());
            clearHelper(node->getRightChild());
            delete node;
        }
    }

    bool findHelper(E param, Node <E> * node)
    {
        if(node == NULL)
            return false;
        if( param == node->getItem())
        {
            return true;
        }

        else if( param > node->getItem())
            return findHelper(param, node->getRightChild());
        else if(param < node->getItem())
            return findHelper(param, node->getLeftChild());
    }

    bool findHelperPrime(E param, Node <E> * node)
    {

        if(node == NULL)
            return false;
        if( param == node->getItem())
        {
//            cout << "boltu" << endl;
            if(node->isLeaf())
            {
//                cout << "goltu " << endl;
                return true;
            }

            else
                return false;
        }

        else if( param > node->getItem())
            return findHelperPrime(param, node->getRightChild());
        else if(param < node->getItem())
            return findHelperPrime(param, node->getLeftChild());
    }







    Node <E> * insertHelper(E param, Node <E> *node)
    {
        if(node == NULL)
            return new Node<E> (param);

        if(param < node -> getItem())
            node -> setLeft(insertHelper(param, node->getLeftChild()));
        else if(param > node->getItem())
            node ->setRight(insertHelper(param, node->getRightChild()));

        return node;

    }

    Node <E> *getMax (Node <E> *node)
    {
        if ( node -> getRightChild() == NULL )
            return node;
        else
            return getMax(node->getRightChild());
    }

    Node <E> *deleteMax(Node <E> *node)
    {
        if ( node -> getRightChild() == NULL )
            return node->getLeftChild();
        else
        {
            node -> setRight(deleteMax(node->getRightChild()));
            return node;
        }
    }

    Node <E> *removeHelper(E param, Node <E> *node)
    {
        if (node == NULL)
            return NULL;

        if(param > node->getItem())
            node -> setRight(removeHelper(param, node->getRightChild()));
        else if(param < node->getItem())
            node ->setLeft(removeHelper(param, node->getLeftChild()));
        else
        {
            Node <E> *tmp = node;
            if ( node -> getLeftChild() == NULL)
            {
                node = node ->getRightChild();
                delete tmp;
            }
            else if( node ->getRightChild() == NULL)
            {
                node = node -> getLeftChild();
                delete tmp;
            }
            else
            {
                tmp = getMax(node -> getLeftChild());
                node ->setItem(tmp-> getItem());
                node -> setLeft(deleteMax(node->getLeftChild()));
                delete tmp;
            }

        }


        return node;
    }

    void preOrderHelper(Node <E> * node)
    {
        if (node == NULL)
            return;
        cout << node->getItem() << " ";
        preOrderHelper(node->getLeftChild());
        preOrderHelper(node->getRightChild());
    }

    void inOrderHelper(Node <E> *node)
    {
        if(node == NULL)
            return;
        inOrderHelper(node ->getLeftChild());
        cout << node->getItem() << " ";
        inOrderHelper(node ->getRightChild());
    }

    void postOrderHelper(Node <E> *node)
    {
        if(node == NULL)
            return;
        postOrderHelper(node->getLeftChild());
        postOrderHelper(node->getRightChild());
        cout << node->getItem() << " ";
    }

    void printHelper(Node <E> *node)
    {
        if(node == NULL) return;

        cout << node->getItem();
        if( node -> isLeaf() == false)
        {
            cout << "(";
            printHelper(node->getLeftChild());
            cout << ")(";
            printHelper(node->getRightChild());
            cout << ")";
        }


    }

    int count_nodes(Node <E> *node)
    {
        if(node == NULL)
            return 0;
        return 1+count_nodes(node->getLeftChild())+count_nodes(node->getRightChild());
    }

    Node <E>* getMinHelper(Node <E> *node)
    {
        if(node->getLeftChild() == NULL)
            return node;
        else
            getMinHelper(node->getLeftChild());
    }


    int heightHelper(Node <E> *node)
    {
        if(node == NULL)
            return 0;

        int LeftHeight= heightHelper(node->getLeftChild());
        int RightHeight = heightHelper(node->getRightChild());

        if(LeftHeight > RightHeight)
            return 1+LeftHeight;
        else
            return 1+RightHeight;
    }

public:
    BST ()
    {
        root = NULL;
        count = 0;
    }

    ~BST()
    {
        clearHelper(root);
    }

    bool find(E param)
    {
        return findHelper(param, root);
    }

    bool find2(E param)
    {
        return findHelperPrime(param, root);
    }
    void insert(E param)
    {
        root = insertHelper(param, root);
        count++;
    }

    bool Delete(E param)
    {
        bool state  = find(param);
//        cout << " HIIII ::: " << state << endl;
        if(state)
        {
            root = removeHelper(param, root);
            count -- ;
            return true;
        }

        return false;
    }

    void print()
    {
        printHelper(root);
        cout << endl;
    }
    void preOrder()
    {
        preOrderHelper(root);
    }
    void postOrder()
    {
        postOrderHelper(root);
    }
    void inOrder()
    {
        inOrderHelper(root);
    }

    int count1()
    {
        return count_nodes(root);
    }

    int getMin()
    {
        Node <E> *tmp = getMinHelper(root);
        return tmp->getItem();
    }

    int getHeight()
    {
        int height = heightHelper(root);
        return height;
    }


};

//int main()
//{
//    Node <int> n1;
//    cout << sizeof(n1) << endl;
//}



int main()
{
    BST <int> b1;
    b1.insert(10);
    b1.print();
    b1.insert(11);
    b1.print();
    cout << b1.find(6) << endl;
    b1.insert(6);
    b1.print();
    cout << b1.find(6) << endl;
    b1.insert(4);
    b1.print();
    cout << b1.find(11) << endl;
    b1.insert(17);
    b1.print();
    b1.insert(8);
    b1.print();
    b1.insert(7);
    b1.print();
    b1.insert(21);
    b1.print();
    b1.insert(9);
    b1.print();
    b1.inOrder();

    cout << endl;
    b1.preOrder();
    cout << endl;
    b1.postOrder();
    cout << endl;
    cout << b1.find(9) << endl;
    cout << b1.Delete(9) << endl;
    b1.print();
    cout << b1.Delete(11) << endl;
    b1.print();
    cout << "Total nodes are : " << b1.count1() << endl;
    cout << "Minimum value is : " << b1.getMin() << endl;
    cout << "Height is : " << b1.getHeight() << endl;







    return 0;
}
