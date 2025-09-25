# GetPriorityClass function

## Description

Retrieves the priority class for the specified process. This value, together with the priority value of each thread of the process, determines each thread's base priority level.

## Parameters

### `hProcess` [in]

A handle to the process.

The handle must have the **PROCESS_QUERY_INFORMATION** or **PROCESS_QUERY_LIMITED_INFORMATION** access right. For more information, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

**Windows Server 2003 and Windows XP:** The handle must have the **PROCESS_QUERY_INFORMATION** access right.

## Return value

If the function succeeds, the return value is the priority class of the specified process.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The process's priority class is one of the following values.

| Return code/value | Description |
| --- | --- |
| **ABOVE_NORMAL_PRIORITY_CLASS**<br><br>0x00008000 | Process that has priority above **NORMAL_PRIORITY_CLASS** but below **HIGH_PRIORITY_CLASS**. |
| **BELOW_NORMAL_PRIORITY_CLASS**<br><br>0x00004000 | Process that has priority above **IDLE_PRIORITY_CLASS** but below **NORMAL_PRIORITY_CLASS**. |
| **HIGH_PRIORITY_CLASS**<br><br>0x00000080 | Process that performs time-critical tasks that must be executed immediately for it to run correctly. The threads of a high-priority class process preempt the threads of normal or idle priority class processes. An example is the Task List, which must respond quickly when called by the user, regardless of the load on the operating system. Use extreme care when using the high-priority class, because a high-priority class CPU-bound application can use nearly all available cycles. |
| **IDLE_PRIORITY_CLASS**<br><br>0x00000040 | Process whose threads run only when the system is idle and are preempted by the threads of any process running in a higher priority class. An example is a screen saver. The idle priority class is inherited by child processes. |
| **NORMAL_PRIORITY_CLASS**<br><br>0x00000020 | Process with no special scheduling needs. |
| **REALTIME_PRIORITY_CLASS**<br><br>0x00000100 | Process that has the highest possible priority. The threads of a real-time priority class process preempt the threads of all other processes, including operating system processes performing important tasks. For example, a real-time process that executes for more than a very brief interval can cause disk caches not to flush or cause the mouse to be unresponsive. |

## Remarks

Every thread has a base priority level determined by the thread's priority value and the priority class of its process. The operating system uses the base priority level of all executable threads to determine which thread gets the next slice of CPU time. Threads are scheduled in a round-robin fashion at each priority level, and only when there are no executable threads at a higher level will scheduling of threads at a lower level take place.

For a table that shows the base priority levels for each combination of priority class and thread priority value, see [Scheduling Priorities](https://learn.microsoft.com/windows/desktop/ProcThread/scheduling-priorities).

Priority class is maintained by the executive, so all processes have a priority class that can be queried.

#### Examples

For an example, see
[Taking a Snapshot and Viewing Processes](https://learn.microsoft.com/windows/desktop/ToolHelp/taking-a-snapshot-and-viewing-processes).

## See also

[GetThreadPriority](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadpriority)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Processes](https://learn.microsoft.com/windows/desktop/ProcThread/child-processes)

[Scheduling Priorities](https://learn.microsoft.com/windows/desktop/ProcThread/scheduling-priorities)

[SetPriorityClass](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setpriorityclass)

[SetThreadPriority](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadpriority)