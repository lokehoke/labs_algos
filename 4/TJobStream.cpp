#include "TJobStream.hpp"
#include <cstdlib>

TJobStream::TJobStream(double Chance) noexcept
    : chance(Chance)
{
}

std::optional<int> TJobStream::GetJob() const noexcept
{
    if (static_cast<double>(std::rand()) / RAND_MAX > chance)
    {
        return ++Id;
    }
    else
    {
        return {};
    }
}
