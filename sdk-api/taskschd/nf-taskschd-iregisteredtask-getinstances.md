# IRegisteredTask::GetInstances

## Description

Returns all instances of the currently running registered task.

**Note** **IRegisteredTask::GetInstances** will only return instances of the currently running registered task that are running at or below a user's security context. For example, for members of the Administrators group, **GetInstances** will return all instances of the currently running registered task, but for members of the Users group, **GetInstances** will only return instances of the currently running registered task that are running under the Users group security context.

## Parameters

### `flags`

This parameter is reserved for future use and must be set to 0.

### `ppRunningTasks` [out]

An [IRunningTaskCollection](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-irunningtaskcollection) interface that contains all currently running instances of the task under the user's context.

Pass in a reference to a **NULL** [IRunningTaskCollection](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-irunningtaskcollection) interface pointer. Referencing a non-**NULL** pointer can cause a memory leak because the pointer will be overwritten.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation completed successfully. |
| **E_INVALIDARG** | A non-null flag was passed into the *flags* parameter. |
| **E_POINTER** | NULL was passed into the *ppRunningTasks* parameter. |

## See also

[IRegisteredTask](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iregisteredtask)

[IRunningTaskCollection](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-irunningtaskcollection)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)