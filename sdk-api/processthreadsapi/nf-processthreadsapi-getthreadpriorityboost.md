# GetThreadPriorityBoost function

## Description

Retrieves the priority boost control state of the specified thread.

## Parameters

### `hThread` [in]

A handle to the thread. The handle must have the **THREAD_QUERY_INFORMATION** or **THREAD_QUERY_LIMITED_INFORMATION** access right. For more information, see
[Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

**Windows Server 2003 and Windows XP:** The handle must have the **THREAD_QUERY_INFORMATION** access right.

### `pDisablePriorityBoost` [out]

A pointer to a variable that receives the priority boost control state. A value of TRUE indicates that dynamic boosting is disabled. A value of FALSE indicates normal behavior.

## Return value

If the function succeeds, the return value is nonzero. In that case, the variable pointed to by the *pDisablePriorityBoost* parameter receives the priority boost control state.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[OpenThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthread)

[Priority Boosts](https://learn.microsoft.com/windows/desktop/ProcThread/priority-boosts)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Scheduling Priorities](https://learn.microsoft.com/windows/desktop/ProcThread/scheduling-priorities)

[SetThreadPriorityBoost](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadpriorityboost)

[Threads](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-threads)