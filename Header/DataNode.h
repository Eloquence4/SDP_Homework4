#ifndef DataNodeDec
#define DataNodeDec

#include <cstddef>

struct DataNode
{
    __int32 key;
    char* data;
    size_t DataSize;

    bool operator<(const DataNode& rhs) const;

    bool operator==(const DataNode& rhs) const;

    bool operator>(const DataNode& rhs) const;

    bool operator<=(const DataNode& rhs) const;

    bool operator>=(const DataNode& rhs) const;

    private:

    int compData(const char* rhs) const
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
};

#endif // DataNodeDec
