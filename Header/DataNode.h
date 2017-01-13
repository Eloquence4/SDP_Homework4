#ifndef DataNodeDec
#define DataNodeDec

#include <cstddef>
#include <fstream>

struct DataNode
{
    __int32 key;
    char* data;
    __int32 DataSize;

    DataNode();
    ~DataNode();
    DataNode(const DataNode& source);
    DataNode(DataNode&& source);
    DataNode& operator=(const DataNode& rhs);
    DataNode& operator=(DataNode&& rhs);

    DataNode(__int32 _key, char*&& _data, __int32 _DataSize);
    DataNode(__int32 _key, const char* _data, __int32 _DataSize);

    bool operator<(const DataNode& rhs) const;

    bool operator==(const DataNode& rhs) const;

    bool operator>(const DataNode& rhs) const;

    bool operator<=(const DataNode& rhs) const;

    bool operator>=(const DataNode& rhs) const;

    int compData(const char* rhs) const;

    void BinaryRead(std::ifstream& file);

    private:

    void assign(DataNode& rhs);

    void copy(__int32 _key, char* _data, __int32 _DataSize);

};

#endif // DataNodeDec
