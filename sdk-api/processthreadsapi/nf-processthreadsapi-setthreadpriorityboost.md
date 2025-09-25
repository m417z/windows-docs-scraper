# SetThreadPriorityBoost function

## Description

Disables or enables the ability of the system to temporarily boost the priority of a thread.

## Parameters

### `hThread` [in]

A handle to the thread whose priority is to be boosted. The handle must have the **THREAD_SET_INFORMATION** or **THREAD_SET_LIMITED_INFORMATION** access right. For more information, see
[Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

**Windows Server 2003 and Windows XP:** The handle must have the **THREAD_SET_INFORMATION** access right.

### `bDisablePriorityBoost` [in]

If this parameter is **TRUE**, dynamic boosting is disabled. If the parameter is **FALSE**, dynamic boosting is enabled.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When a thread is running in one of the dynamic priority classes, the system temporarily boosts the thread's priority when it is taken out of a wait state. If
**SetThreadPriorityBoost** is called with the *DisablePriorityBoost* parameter set to **TRUE**, the thread's priority is not boosted. To restore normal behavior, call
**SetThreadPriorityBoost** with *DisablePriorityBoost* set to **FALSE**.

## See also

[GetThreadPriorityBoost](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadpriorityboost)

[OpenThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthread)

[Priority Boosts](https://learn.microsoft.com/windows/desktop/ProcThread/priority-boosts)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Scheduling Priorities](https://learn.microsoft.com/windows/desktop/ProcThread/scheduling-priorities)

[Threads](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-threads)