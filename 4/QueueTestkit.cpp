#include <array>
#include <iostream>

#include "TJobStream.hpp"
#include "TProc.hpp"
#include "TQueue.hpp"

int main()
{
    constexpr size_t clusterCount = 5;
    size_t TickCount = 20;
    size_t maxSizeQueue = 100;
    double q1, q2;
    std::cout << "Enter tick count, max size of queue, q1, q2" << std::endl;
    std::cin >> TickCount >> maxSizeQueue >> q1 >> q2;

    std::array<TProc, clusterCount> cluster{{{q1}, {q1}, {q1}, {q1}, {q1}}};
    TJobStream jobStream(q2);
    TQueue<int> queue(maxSizeQueue);

    size_t taskComplite = 0;
    size_t taskMiss = 0;

    for (size_t i = 0; i < TickCount; ++i)
    {
        auto job = jobStream.GetJob();
        if (job)
        {
            if (!queue.IsFull())
            {
                queue.Put(*job);
            }
            else
            {
                ++taskMiss;
            }
        }

        for (auto &proc : cluster)
        {
            if (!queue.IsEmpty() && !proc.isProcBusy())
            {
                auto task = proc.RunNewJob(queue.Get());
                if (task != -1)
                {
                    // std::cout << task << " ";
                    ++taskComplite;
                }
            }
        }
    }

    for (auto &proc : cluster)
    {
        if (proc.getIdTask() != -1)
        {
            // std::cout << proc.getIdTask() << " ";
            ++taskMiss;
        }
    }

    std::cout
        << static_cast<double>(taskComplite / static_cast<double>(taskComplite + taskMiss)) << std::endl
        << static_cast<double>(taskMiss / static_cast<double>(taskComplite + taskMiss)) << std::endl;

    return 0;
}