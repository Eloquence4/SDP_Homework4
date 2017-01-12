#include <iostream>
#include <fstream>
#include "Header/BinaryTree.h"
#include "Header/Vector.h"
#include "Header/DataNode.h"

void createBalancedTree(BinaryTree<DataNode>& tree, const Vector<DataNode>& vector);
void createBalancedTree(BinaryTree<DataNode>& tree, const Vector<DataNode>& vector, size_t start, size_t end);

int main(int argc, char* argv[])
{
    if(argc == 1)
    {
        std::cout << "This program requires more command line arguments!\n";
        return 0;
    }
    std::ifstream file(argv[1], std::ios::in | std::ios::binary);

    if(!file)
    {
        std::cout << "Error openning the file!\n";
        return 0;
    }

    Vector<DataNode> fileData;

    while(file.good())
    {
        DataNode a;
        a.BinaryRead(file);

        int index = 0;

        for(; index < fileData.size(); index++) // Sorting the data while adding it into the vector
            if(a <= fileData[index])
                break;

        fileData.insert(index, std::move(a));
    }

    file.close();

    BinaryTree<DataNode> tree;

    createBalancedTree(tree, fileData); // Will be assigning all of the data nodes, because we will not be using the vector afterwards


    return 0;
}

void createBalancedTree(BinaryTree<DataNode>& tree, const Vector<DataNode>& vector)
{
    createBalancedTree(tree, vector, 0, vector.size()-1);
}

void createBalancedTree(BinaryTree<DataNode>& tree, const Vector<DataNode>& vector, size_t start, size_t end)
{
    if(start == end)
        tree.Add(std::move(vector[start]));
    else
    {
        size_t mid = start + (end - start)/2;
        tree.Add(std::move(vector[mid]));

        if(start < mid)
            createBalancedTree(tree, vector, start, mid-1);
        if(end > mid)
            createBalancedTree(tree, vector, mid+1, end);
    }
}

