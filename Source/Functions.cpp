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

    std::cout << remove_all(tree, key) << '\n';
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
