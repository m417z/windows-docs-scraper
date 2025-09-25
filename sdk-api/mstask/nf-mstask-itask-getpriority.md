# ITask::GetPriority

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

This method retrieves the priority for the [task](https://learn.microsoft.com/windows/desktop/TaskSchd/t).

## Parameters

### `pdwPriority` [out]

A pointer to a **DWORD** that contains the priority for the current task. The priority value determines the frequency and length of the time slices for a process. This applies only to the Windows Server 2003, Windows XP, and Windows 2000 operating systems. It is taken from the CreateProcess priority class and can be one of the following flags (in descending order of thread scheduling priority):

* REALTIME_PRIORITY_CLASS
* HIGH_PRIORITY_CLASS
* NORMAL_PRIORITY_CLASS
* IDLE_PRIORITY_CLASS

## Return value

The
**GetPriority** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## See also

[ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask)

[SetPriority](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itask-setpriority)