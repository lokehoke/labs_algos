#pragma once

class TProc
{
public:
    TProc() = default;
    ~TProc() = default;

    int RunNewJob(int id) noexcept;
    bool isProcBusy() const noexcept;
    int getIdTask() const noexcept;

private:
    int Id = -1;
    const double chance = 0.5;
};
