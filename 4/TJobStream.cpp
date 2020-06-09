#include "TJobStream.hpp"
#include <cstdlib>

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
