# SetProcessPriorityBoost function

## Description

Disables or enables the ability of the system to temporarily boost the priority of the threads of the specified process.

## Parameters

### `hProcess` [in]

A handle to the process. This handle must have the PROCESS_SET_INFORMATION access right. For more information, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `bDisablePriorityBoost` [in]

If this parameter is TRUE, dynamic boosting is disabled. If the parameter is FALSE, dynamic boosting is enabled.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When a thread is running in one of the dynamic priority classes, the system temporarily boosts the thread's priority when it is taken out of a wait state. If
**SetProcessPriorityBoost** is called with the *DisablePriorityBoost* parameter set to TRUE, its threads' priorities are not boosted. This setting affects all existing threads and any threads subsequently created by the process. To restore normal behavior, call
**SetProcessPriorityBoost** with *DisablePriorityBoost* set to FALSE.

## See also

[GetProcessPriorityBoost](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocesspriorityboost)

[Priority Boosts](https://learn.microsoft.com/windows/desktop/ProcThread/priority-boosts)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Processes](https://learn.microsoft.com/windows/desktop/ProcThread/child-processes)

[Scheduling Priorities](https://learn.microsoft.com/windows/desktop/ProcThread/scheduling-priorities)