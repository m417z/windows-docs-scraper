# ITaskService::GetRunningTasks

## Description

Gets a collection of running tasks.

**Note** **ITaskService::GetRunningTasks** will only return a collection of running tasks that are running at or below a user's security context. For example, for members of the Administrators group, **GetRunningTasks** will return a collection of all running tasks, but for members of the Users group, **GetRunningTasks** will only return a collection of tasks running under the Users group security context.

## Parameters

### `flags` [in]

A value from the [TASK_ENUM_FLAGS](https://learn.microsoft.com/windows/desktop/api/taskschd/ne-taskschd-task_enum_flags) enumeration. Pass in 0 to return a collection of running tasks that are not hidden tasks.

### `ppRunningTasks` [out]

An [IRunningTaskCollection](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-irunningtaskcollection) interface that contains the currently running tasks.

Pass in a reference to a **NULL** [IRunningTaskCollection](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-irunningtaskcollection) interface pointer. Referencing a non-**NULL** pointer can cause a memory leak because the pointer will be overwritten.

## Return value

This method can return one of these values.

|  | Description |
| --- | --- |
| **E_INVALIDARG** | An invalid argument was specified in the method call. Passing a nonzero value to the *flags* parameter will return **E_INVALIDARG**. |
| **S_OK** | The operation completed successfully. |
| **E_POINTER** | NULL was passed into the *retVal* parameter. |
| **HRESULT_FROM_WIN32(ERROR_ONLY_IF_CONNECTED)** | The user has not connected to the service. |

## See also

[IRunningTaskCollection](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-irunningtaskcollection)

[ITaskService](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskservice)

[TASK_ENUM_FLAGS](https://learn.microsoft.com/windows/desktop/api/taskschd/ne-taskschd-task_enum_flags)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)