#include "../Header/DataNode.h"

bool DataNode::operator<(const DataNode& rhs) const
{
    if(key < rhs.key)
        return true;

    if(key == rhs.key && compData(rhs.data) < 0)
        return true;

    return false;
}

bool DataNode::operator==(const DataNode& rhs) const
{
    if(key == rhs.key && compData(rhs.data) == 0)
        return true;

    return false;
}

bool DataNode::operator>(const DataNode& rhs) const
{
    if(key > rhs.key)
        return true;

    if(key == rhs.key && compData(rhs.data) > 0)
        return true;

    return false;
}

bool DataNode::operator<=(const DataNode& rhs) const
{
    return !(*this > rhs);
}

bool DataNode::operator>=(const DataNode& rhs) const
{
    return !(*this < rhs);
}

int DataNode::compData(const char* rhs) const
{
    const char* data2 = data;

    while(*data2 == *rhs)
    {
        if(*data2 == '\0')
            return true;

        rhs++;
        data2++;
    }

    return *data2 - *rhs;
}