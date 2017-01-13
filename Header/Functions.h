#ifndef FunctionsDef
#define FunctionsDef

#include "BinaryTree.h"
#include "DataNode.h"

void add(BinaryTree<DataNode>& tree);
void remove(BinaryTree<DataNode>& tree);
void remove_all(BinaryTree<DataNode>& tree);
void search(BinaryTree<DataNode>& tree);

__int32 read_key();
char* read_data();

#endif // FunctionsDef
