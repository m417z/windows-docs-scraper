# ITask::SetPriority

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

This method sets the priority for the [task](https://learn.microsoft.com/windows/desktop/TaskSchd/t).

## Parameters

### `dwPriority` [in]

A **DWORD** that specifies the priority for the current task. The priority of a task determines the frequency and length of the time slices for a process. This applies only to the Windows Server 2003, Windows XP, and Windows 2000 operating systems. These values are taken from the **CreateProcess** priority class and can be one of following flags (in descending order of thread scheduling priority):

* REALTIME_PRIORITY_CLASS
* HIGH_PRIORITY_CLASS
* NORMAL_PRIORITY_CLASS
* IDLE_PRIORITY_CLASS

## Return value

The
**SetPriority** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |

## Remarks

After setting the priority of a task, call **IPersistFile::Save** to save the modified task object to disk.

#### Examples

For more information and an example of how to set the priority of a task, see [C/C++ Code Example: Setting Task Priority](https://learn.microsoft.com/windows/desktop/TaskSchd/c-c-code-example-setting-task-priority).

## See also

[GetPriority](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itask-getpriority)

[ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask)