#include "../Header/Functions.h"

void add(BinaryTree<DataNode>& tree)
{
    __int32 key = read_key();
    char* data = read_data();
    __int32 dataSize = strlen(data);

    tree.Add(DataNode(key, std::move(data), dataSize));
}
