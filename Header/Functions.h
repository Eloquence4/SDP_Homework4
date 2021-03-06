#ifndef FunctionsDef
#define FunctionsDef

#include "BinaryTree.h"
#include "DataNode.h"

const int buffer_max_size = 1048576; // 1 MB

void add(BinaryTree<DataNode>& tree);
void remove(BinaryTree<DataNode>& tree);
void remove_all(BinaryTree<DataNode>& tree);
void search(BinaryTree<DataNode>& tree);

void remove_all(BinaryTree<DataNode>::TreeIterator it, __int32 key, int& count);

__int32 read_key();
char* read_data();

#endif // FunctionsDef
