#include "../Header/DataNode.h"

DataNode::DataNode()
    : key(0)
    , data(nullptr)
    , DataSize(0)
{ }

DataNode::~DataNode()
{
    delete[] data;
}

DataNode::DataNode(const DataNode& source)
    : key(0)
    , data(nullptr)
    , DataSize(0)
{
    copy(source.key, source.data, source.DataSize);
}

DataNode::DataNode(DataNode&& source)
{
    assign(source);
}

DataNode& DataNode::operator=(const DataNode& rhs)
{
    if(this != &rhs)
        copy(rhs.key, rhs.data, rhs.DataSize);

    return *this;
}

DataNode& DataNode::operator=(DataNode&& rhs)
{
    if(this != &rhs)
        assign(rhs);

    return *this;
}

DataNode::DataNode(__int32 _key, char*& _data, __int32 _DataSize)
    : key(_key)
    , data(_data)
    , DataSize(_DataSize)
{
    _data = nullptr;
}

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
    __int32 counter = 0;

    while(counter < DataSize)
    {
        if(*rhs != *data2)
            return *data2 - *rhs;
        rhs++;
        data2++;
        counter++;
    }

    return 0;
}

void DataNode::BinaryRead(std::ifstream& file)
{
    file.read((char*) &key, sizeof(key));
    file.read((char*) &DataSize, sizeof(DataSize));

    delete[] data;
    data = new char[DataSize];

    file.read(data, sizeof(char)*DataSize);
}

void DataNode::assign(DataNode& rhs)
{
    key = rhs.key;
    data = rhs.data;
    DataSize = rhs.DataSize;

    rhs.key = 0;
    rhs.data = 0;
    rhs.DataSize = 0;
}

void DataNode::copy(__int32 _key, char * _data, __int32 _DataSize)
{
    key = _key;
    DataSize = _DataSize;
    char* newData = new char[DataSize];

    for(int i = 0; i < DataSize; i++)
        newData[i] = _data[i];

    delete[] data;
    data = newData;
}