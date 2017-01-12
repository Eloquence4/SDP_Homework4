#ifndef BinaryTreeIteratorDef
#define BinaryTreeIteratorDef

class TreeIterator
{
    friend class BinaryTree;

public:

    // O(1), returns the data of the node the iterator is holding
    // Unstable, throws INVALID_ITERATOR
    VarType& data()
    {
        if(ptr == nullptr)
            throw INVALID_ITERATOR;

        return ptr->Data;
    }

    // O(logN) and O(N) in the worst case, returns and iterator to the target, does not change this iterator
    // Unstable, throws ITERATOR_NOT_FOUND
    TreeIterator search(const VarType& key)
    {
        return search(ptr, key);
    }

    // O(1), returns the data as a constant
    // Unstable, throws INVALID_ITERATOR
    const VarType& data() const
    {
        if(ptr == nullptr)
            throw INVALID_ITERATOR;

        return ptr->Data;
    }

    // O(1), the iterator goes to the left child
    // Unstable, throws IT_NO_LEFT_CHILD
    TreeIterator& operator++()
    {
        if(ptr->Left == nullptr)
            throw IT_NO_LEFT_CHILD;

        ptr = ptr->Left;
    }

    // O(1), the iterator goes to the left child
    // Unstable, throws IT_NO_LEFT_CHILD
    void GoLeft()
    {
        ++(*this);
    }

    // O(1), the iterator goes to the right child
    // Unstable, throws IT_NO_RIGHT_CHILD
    TreeIterator operator++(int)
    {
        if(ptr->Right == nullptr)
            throw IT_NO_RIGHT_CHILD;

        ptr = ptr->Right;
    }

    // O(1), the iterator goes to the right child
    // Unstable, throws IT_NO_RIGHT_CHILD
    void GoRight()
    {
        (*this)++;
    }

    // O(1), checks if the target of the iterator is a leaf
    bool leaf() const
    {
        if(ptr->Left || ptr->Right)
            return false;
        
        return true;
    }

    // O(1) or O(logN) if there are children on both sides, removes left child
    void remove_left()
    {
        if(ptr->Left == nullptr)
            return;
        remove(ptr->Left);
    }

    // O(1) or O(logN) if there are children on both sides, removes right child
    void remove_right()
    {
        if(ptr->Right == nullptr)
            return;
        remove(ptr->Right);
    }

private:

    TreeIterator(Tree_Node<VarType>* _ptr)
        : top(_ptr)
        , ptr(_ptr)
    { }

    TreeIterator(Tree_Node<VarType>* _top, Tree_Node<VarType>* _ptr)
        : top(_top)
        , ptr(_ptr)
    { };

    TreeIterator search(Tree_Node<VarType>* node, const VarType& key)
    {
        if(node == nullptr)
            throw NOT_FOUND;

        if(key > node->Data)
            return search(node->Right, key);
        else if(key < node->Data)
            return search(node->Left, key);
        else
            return TreeIterator(top, node);
    }

    Tree_Node<VarType>* FindSmallest(Tree_Node<VarType>*& node)
    {
        if(node->Left != nullptr)
            return FindSmallest(node->Left);
        else
        {
            Tree_Node<VarType>* temp = node;

            node = nullptr;

            return temp;
        }
    }

    Tree_Node<VarType>* FindBiggest(Tree_Node<VarType>*& node)
    {
        if(node->Right != nullptr)
            return FindSmallest(node->Left);
        else
        {
            Tree_Node<VarType>* temp = node;

            node = nullptr;

            return temp;
        }
    }

    void remove(Tree_Node<VarType>*& node)
    {
        if(node->Occurrences > 1)
            node->Occurrences--;
        else if(node->Left && node->Right)
        {
            Tree_Node<VarType>* temp = node;

            if((size_t)&node & 2) // Some randomness when it choses Left or Right
                node = FindSmallest(node->Right);
            else
                node = FindBiggest(node->Left);

            node->Left = temp->Left;
            node->Right = temp->Right;

            delete temp;
        }
        else if(node->Left || node->Right)
        {
            Tree_Node<VarType>* temp = node;

            if(node->Left)
                node = node->Left;
            else if(node->Right)
                node = node->Right;

            delete temp;
        }
        else
        {
            delete node;

            if(top == node)
                top == nullptr;

            node = nullptr;
        }
    }

    Tree_Node<VarType>*& top;
    Tree_Node<VarType>*  ptr;

};

#endif // BinaryTreeIteratorDef
