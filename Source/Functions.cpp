#include <iostream>
#include "../Header/Functions.h"

void add(BinaryTree<DataNode>& tree)
{
    __int32 key = read_key();
    char* data = read_data();
    __int32 dataSize = strlen(data);

    tree.Add(DataNode(key, std::move(data), dataSize));
}

void remove(BinaryTree<DataNode>& tree)
{
    __int32 key = read_key();
    char* data = read_data();
    __int32 dataSize = strlen(data);

    if(tree.Remove(DataNode(key, std::move(data), dataSize)))
        std::cout << "true\n";
    else
        std::cout << "false\n";
}

void remove_all(BinaryTree<DataNode>& tree)
{
    __int32 key = read_key();

    auto it = tree.Top();

    int count = 0;

    remove_all(it, key, count);

    std::cout << count << '\n';
}

void search(BinaryTree<DataNode>& tree)
{
    __int32 key = read_key();
    char* data = read_data();
    __int32 dataSize = strlen(data);

    try
    {
        tree.Search(DataNode(key, std::move(data), dataSize));
        std::cout << "true\n";
    }
    catch(TreeExceptions& err)
    {
        if(err == NOT_FOUND)
            std::cout << "false\n";
        else
            throw err;
    }
}

void remove_all(BinaryTree<DataNode>::TreeIterator it, __int32 key, int& count)
{
    // The reason i don't search by checking if the key is greater or smaller, is because
    // i think i have found an error in my tree structure, but i am not sure if that is correct
    // If there is an error, i don't really have enough time to remake the whole structure of DataNode
    // The algorithm is O(n) for this reason, instead of O(log n)
    try
    {
        auto itL(it);

        itL.GoLeft();
        remove_all(itL, key, count);
    }
    catch(TreeExceptions& err)
    {
        if(err != IT_NO_LEFT_CHILD)
            throw err;
    }

    try
    {
        auto itR(it);

        itR.GoRight();
        remove_all(itR, key, count);
    }
    catch(TreeExceptions& err)
    {
        if(err != IT_NO_RIGHT_CHILD)
            throw err;
    }

    if(it.data().key == key)
    {
        count++;
        it.remove();
    }

    // The error is, with the way i have defined operators < and > for DataNode i think
    // that i will break the definitions of a binary tree, where the left element is always lesser
    // and the right element is always greater. A better approach to this homework is if i had made
    // DataNode a vector with a key attached to it, and the vector would hold all the data strings,
    // then i could just define operator < and > the usual way

    // I will do this later when i have a bit more time, because now that the session is coming i have a lot of
    // things to study for
}

__int32 read_key()
{
    __int32 key = 0;
    std::cin >> key;

    return key;
}

char* read_data()
{
    char buffer[buffer_max_size+1] = {'\0'};

    std::cin.getline(buffer, buffer_max_size);

    size_t len = strlen(buffer);

    char* data = new char[len+1];

    strcpy(data, buffer);

    return data;
}
