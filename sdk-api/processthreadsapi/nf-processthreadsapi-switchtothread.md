# SwitchToThread function

## Description

Causes the calling thread to yield execution to another thread that is ready to run on the current processor. The operating system selects the next thread to be executed.

## Return value

If calling the
**SwitchToThread** function caused the operating system to switch execution to another thread, the return value is nonzero.

If there are no other threads ready to execute, the operating system does not switch execution to another thread, and the return value is zero.

## Remarks

The yield of execution is in effect for up to one thread-scheduling time slice on the processor of the calling thread. The operating system will not switch execution to another processor, even if that processor is idle or is running a thread of lower priority.

After the yielding thread's time slice elapses, the operating system reschedules execution for the yielding thread. The rescheduling is determined by the priority of the yielding thread and the status of other threads that are available to run.

Note that the operating system will not switch to a thread that is being prevented from running only by concurrency control. For example, an I/O completion port or thread pool limits the number of associated threads that can run. If the maximum number of threads is already running, no additional associated thread can run until a running thread finishes. If a thread uses **SwitchToThread** to wait for one of the additional associated threads to accomplish some work, the process might deadlock.

To compile an application that uses this function, define _WIN32_WINNT as 0x0400 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[SuspendThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-suspendthread)

[Suspending Thread Execution](https://learn.microsoft.com/windows/desktop/ProcThread/suspending-thread-execution)

[Threads](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-threads)