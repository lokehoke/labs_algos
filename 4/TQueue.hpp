#pragma once

#include <list>

template <typename T>
class TQueue
{
private:
    size_t MaxSize = 0;
    std::list<T> store;

public:
    TQueue(size_t max) noexcept;
    ~TQueue() = default;

    void Put(const T &val) noexcept;
    T Get() noexcept;
    bool IsFull() const noexcept;
    bool IsEmpty() const noexcept;
};

#include "TQueue.tpp"
