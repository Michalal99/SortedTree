struct Node {
public:
    Node(int val) : value(val), pLeft(nullptr), pRight(nullptr) {};

    ~Node() {
        if (pLeft)
            delete pLeft;
        if (pRight)
            delete pRight;
    };

    int value;
    Node *pLeft, *pRight;
};

// ******************** YOUR CODE HERE ********************

// Returns value indicating whether binary tree passed by a pointer to the root node is sorted
bool AdditionalIsSorted(Node *pRoot, Node *pLeft, Node *pRight) {
    if (pRoot == nullptr)
        return true;
    if (pLeft != nullptr && pRoot->value < pLeft->value)
        return false;
    if (pRight != nullptr && pRoot->value > pRight->value)
        return false;
    return AdditionalIsSorted(pRoot->pLeft, pLeft, pRoot) && AdditionalIsSorted(pRoot->pRight, pRoot, pRight);
}

bool IsSorted(Node *pRoot) {
    return AdditionalIsSorted(pRoot, nullptr, nullptr);
}
// ********************************************************

#include <iostream>

using namespace std;

int main() {

    // This is only simple example.
    // Solution must handle all cases.
    Node* pRoot = new Node(1);
    pRoot->pLeft = new Node(1);
    pRoot->pLeft->pLeft = new Node(0);
    pRoot->pRight = new Node(2);


    if (IsSorted(pRoot)) cout << "Tree is sorted" << endl;
    else cout << "Tree is not sorted" << endl;
    delete pRoot;
    return 0;
}
