#include "TQueue.hpp"

template <typename T>
TQueue<T>::TQueue(size_t size) noexcept
    : MaxSize(size)
{
}

template <typename T>
void TQueue<T>::Put(const T &val) noexcept
{
    if (store.size() < MaxSize)
    {
        store.push_back(val);
    }
}

template <typename T>
T TQueue<T>::Get() noexcept
{
    T el = store.front();
    store.pop_front();
    return el;
}

template <typename T>
bool TQueue<T>::IsFull() const noexcept
{
    return store.size() == MaxSize;
}

template <typename T>
bool TQueue<T>::IsEmpty() const noexcept
{
    return store.empty();
}
