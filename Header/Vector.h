#ifndef VectorDec
#define VectorDec

enum VectorErrors
{
    INVALID_INDEX
};

#include <cstddef>

template <typename VarType>
class Vector
{
    public:

    // G4
    Vector();
    ~Vector();
    Vector(const Vector<VarType>& source);
    Vector<VarType>& operator=(const Vector<VarType>& rhs);
    /////

    // O(1)
    size_t size() const;

    // O(1)
    size_t max_size() const;

    // O(1)
    bool empty() const;

    // O(n)
    void resize(size_t new_size);

    // O(n)
    void shrink_to_fit();

    // O(1)
    // Unstable, throws INVALID_INDEX when index >= Size
    VarType& operator[](size_t index);

    // O(1)
    const VarType& operator[](size_t index) const;

    // O(1)
    void push_back(const VarType& data);

    // O(1)
    void pop_back();

    // O(n)
    // Unstable, throws INVALID_INDEX when index >= Size
    void insert(size_t index, const VarType& data);

    // O(n)
    void remove(size_t index);


    private:

    void clear();
    void copy(VarType* _Data, size_t _MaxSize, size_t _Size);

    VarType* Data;
    size_t MaxSize;
    size_t Size;
};

#include "../HPP/Vector.hpp"

#endif // VectorDec
