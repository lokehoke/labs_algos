#pragma once

#include <optional>

class TJobStream
{
public:
    TJobStream() = default;
    ~TJobStream() = default;

    std::optional<int> GetJob() const noexcept;

private:
    mutable int Id = 0;
    const double chance = 0.5;
};
