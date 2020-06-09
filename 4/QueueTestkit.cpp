#include <array>
#include <iostream>

#include "TJobStream.hpp"
#include "TProc.hpp"
#include "TQueue.hpp"

int main()
{
    constexpr size_t TickCount = 20;
    constexpr size_t clusterCount = 5;
    constexpr size_t maxSizeQueue = 100;

    std::array<TProc, clusterCount> cluster;
    TJobStream jobStream;
    TQueue<int> queue(100);

    size_t taskComplite = 0;

    for (size_t i = 0; i < TickCount; ++i)
    {
        auto job = jobStream.GetJob();
        if (job)
        {
            if (!queue.IsFull())
            {
                queue.Put(*job);
            }
        }

        for (auto &proc : cluster)
        {
            if (!queue.IsEmpty() && !proc.isProcBusy())
            {
                auto task = proc.RunNewJob(queue.Get());
                if (task != -1)
                {
                    std::cout << task << " ";
                    ++taskComplite;
                }
            }
        }
    }

    for (auto &proc : cluster)
    {
        if (proc.getIdTask() != -1)
        {
            std::cout << proc.getIdTask() << " ";
            ++taskComplite;
        }
    }

    std::cout << std::endl
              << taskComplite << std::endl;

    return 0;
}