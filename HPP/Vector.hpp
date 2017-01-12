#ifndef VectorDef
#define VectorDef

//////////////////////////////////////////////// G4

template<typename VarType>
inline Vector<VarType>::Vector()
    : Data(nullptr)
    , MaxSize(0)
    , Size(0)
{ }

template<typename VarType>
inline Vector<VarType>::~Vector()
{
    clear();
}

template<typename VarType>
inline Vector<VarType>::Vector(const Vector<VarType>& source)
    : Data(nullptr)
    , MaxSize(0)
    , Size(0)
{
    copy(source.data, source.MaxSize, source.Size);
}

template<typename VarType>
inline Vector<VarType>& Vector<VarType>::operator=(const Vector<VarType>& rhs)
{
    if(this != &rhs)
        copy(rhs.data, rhs.MaxSize, rhs.Size);

    return *this;
}

//////////////////////////////////////////////// Public

template<typename VarType>
inline size_t Vector<VarType>::size() const
{
    return Size;
}

template<typename VarType>
inline size_t Vector<VarType>::max_size() const
{
    return MaxSize;
}

template<typename VarType>
inline bool Vector<VarType>::empty() const
{
    return Size == 0;
}

template<typename VarType>
inline void Vector<VarType>::resize(size_t new_size)
{
    if(MaxSize == new_size)
        return;

    if(new_size == 0)
        clear();

    if(MaxSize == 0)
    {
        MaxSize = new_size;
        Data = new VarType[new_size];
    }
    else
    {
        Size = new_size < Size ? new_size : Size;

        VarType* _Data = new VarType[new_size];
        MaxSize = new_size;

        for(size_t i = 0; i < Size; i++)
            _Data[i] = Data[i];

        delete[] Data;
        Data = _Data;
    }
}

template<typename VarType>
inline void Vector<VarType>::shrink_to_fit()
{
    resize(Size);
}

template<typename VarType>
inline VarType& Vector<VarType>::operator[](size_t index)
{
    if(index >= Size)
        throw INVALID_INDEX;

    return Data[index];
}

template<typename VarType>
inline const VarType& Vector<VarType>::operator[](size_t index) const
{
    if(index >= Size)
        throw INVALID_INDEX;

    return Data[index];
}

template<typename VarType>
inline void Vector<VarType>::push_back(const VarType& data)
{
    if(MaxSize == 0)
        resize(1);
    else if(Size == MaxSize)
        resize(MaxSize*2);

    Data[Size] = data;
    Size++;
}

template<typename VarType>
inline void Vector<VarType>::push_back(VarType&& data)
{
    if(MaxSize == 0)
        resize(1);
    else if(Size == MaxSize)
        resize(MaxSize * 2);

    Data[Size] = std::move(data);
    Size++;
}

template<typename VarType>
inline void Vector<VarType>::pop_back()
{
    if(Size == 0)
        return;

    Size--;
}

template<typename VarType>
inline void Vector<VarType>::insert(size_t index, const VarType& data)
{
    if(index == Size)
        push_back(data);
    else if(index > Size)
        throw INVALID_INDEX;
    else
    {
        if(Size == MaxSize)
            resize(MaxSize*2);

        for(int i = Size; i > index; i--)
            Data[i] = Data[i-1];

        Data[index] = data;
    }
}

template<typename VarType>
inline void Vector<VarType>::insert(size_t index, VarType&& data)
{
    if(index == Size)
        push_back(data);
    else if(index > Size)
        throw INVALID_INDEX;
    else
    {
        if(Size == MaxSize)
            resize(MaxSize * 2);

        for(int i = Size; i > index; i--)
            Data[i] = Data[i - 1];

        Data[index] = std::move(data);
    }
}

template<typename VarType>
inline void Vector<VarType>::remove(size_t index)
{
    if(index >= Size)
        return;

    for(int i = index; i < Size-1; i++)
        Data[i] = Data[i+1];
}

//////////////////////////////////////////////// Private

template<typename VarType>
inline void Vector<VarType>::clear()
{
    delete[] Data;
    MaxSize = 0;
    Size = 0;
}

template<typename VarType>
inline void Vector<VarType>::copy(VarType* _Data, size_t _MaxSize, size_t _Size)
{
    Size = _Size;
    MaxSize = _MaxSize;

    char* newData = new VarType[_MaxSize];

    for(int i = 0; i < Size; i++)
        newData[i] = _Data[i];
    
    delete[] Data;
    Data = newData;
}

#endif // VectorDec
