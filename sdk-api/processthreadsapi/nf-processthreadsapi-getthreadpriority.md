# GetThreadPriority function

## Description

Retrieves the priority value for the specified thread. This value, together with the priority class of the thread's process, determines the thread's base-priority level.

## Parameters

### `hThread` [in]

A handle to the thread.

The handle must have the **THREAD_QUERY_INFORMATION** or **THREAD_QUERY_LIMITED_INFORMATION** access right. For more information, see
[Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

**Windows Server 2003:** The handle must have the **THREAD_QUERY_INFORMATION** access right.

## Return value

If the function succeeds, the return value is the thread's priority level.

If the function fails, the return value is **THREAD_PRIORITY_ERROR_RETURN**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Windows Phone 8.1:** This function will always return **THREAD_PRIORITY_NORMAL**.

The thread's priority level is one of the following values.

| Return code/value | Description |
| --- | --- |
| **THREAD_PRIORITY_ABOVE_NORMAL**<br><br>1 | Priority 1 point above the priority class. |
| **THREAD_PRIORITY_BELOW_NORMAL**<br><br>-1 | Priority 1 point below the priority class. |
| **THREAD_PRIORITY_HIGHEST**<br><br>2 | Priority 2 points above the priority class. |
| **THREAD_PRIORITY_IDLE**<br><br>-15 | Base priority of 1 for **IDLE_PRIORITY_CLASS**, **BELOW_NORMAL_PRIORITY_CLASS**, **NORMAL_PRIORITY_CLASS**, **ABOVE_NORMAL_PRIORITY_CLASS**, or **HIGH_PRIORITY_CLASS** processes, and a base priority of 16 for **REALTIME_PRIORITY_CLASS** processes. |
| **THREAD_PRIORITY_LOWEST**<br><br>-2 | Priority 2 points below the priority class. |
| **THREAD_PRIORITY_NORMAL**<br><br>0 | Normal priority for the priority class. |
| **THREAD_PRIORITY_TIME_CRITICAL**<br><br>15 | Base-priority level of 15 for **IDLE_PRIORITY_CLASS**, **BELOW_NORMAL_PRIORITY_CLASS**, **NORMAL_PRIORITY_CLASS**, **ABOVE_NORMAL_PRIORITY_CLASS**, or **HIGH_PRIORITY_CLASS** processes, and a base-priority level of 31 for **REALTIME_PRIORITY_CLASS** processes. |

If the thread has the **REALTIME_PRIORITY_CLASS** base class, this function can also return one of the following values: -7, -6, -5, -4, -3, 3, 4, 5, or 6. For more information, see
[Scheduling Priorities](https://learn.microsoft.com/windows/desktop/ProcThread/scheduling-priorities).

## Remarks

Every thread has a base-priority level determined by the thread's priority value and the priority class of its process. The operating system uses the base-priority level of all executable threads to determine which thread gets the next slice of CPU time. Threads are scheduled in a round-robin fashion at each priority level, and only when there are no executable threads at a higher level will scheduling of threads at a lower level take place.

For a table that shows the base-priority levels for each combination of priority class and thread priority value, refer to the
[SetPriorityClass](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setpriorityclass) function.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps.

**Windows Phone 8.1:**Windows Phone Store apps may call this function but it has no effect.

## See also

[GetPriorityClass](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getpriorityclass)

[OpenThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthread)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Scheduling Priorities](https://learn.microsoft.com/windows/desktop/ProcThread/scheduling-priorities)

[SetPriorityClass](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setpriorityclass)

[SetThreadPriority](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadpriority)

[Threads](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-threads)