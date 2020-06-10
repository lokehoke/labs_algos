#include "TProc.hpp"
#include <cstdlib>

TProc::TProc(double Chance) noexcept
    : chance(Chance)
{
}

int TProc::RunNewJob(int id) noexcept
{
    int old = Id;
    Id = id;
    return old;
}

bool TProc::isProcBusy() const noexcept
{
    return static_cast<double>(std::rand()) / RAND_MAX > chance;
}

int TProc::getIdTask() const noexcept
{
    return Id;
}
