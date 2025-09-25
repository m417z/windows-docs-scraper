# ITaskScheduler::AddWorkItem

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

The
**AddWorkItem** method adds a task to the schedule of tasks.

## Parameters

### `pwszTaskName` [in]

A null-terminated string that specifies the name of the task to add. The task name must conform to Windows NT file-naming conventions, but cannot include backslashes because nesting within the task folder object is not allowed.

### `pWorkItem` [in]

A pointer to the task to add to the schedule.

## Return value

The
**AddWorkItem** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **ERROR_FILE_EXISTS** | A task with the specified name already exists. The actual return value is HRESULT_FROM_WIN32(ERROR_FILE_EXISTS). |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available to complete the operation. |

## Remarks

Task scheduler provides two methods for adding work items:
[NewWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itaskscheduler-newworkitem) and
**AddWorkItem**. Of these methods, each has its specific advantage.
**AddWorkItem** prevents naming collisions, but it also requires two disk write operations per call. One write operation is performed when the call to
**AddWorkItem** creates an empty work item object on the disk, followed by another write operation when **IPersistFile::Save** is called.

[NewWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itaskscheduler-newworkitem) does not prevent naming collisions, but it requires only one disk write operation when **IPersistFile::Save** is called. Although
**NewWorkItem** is more efficient with disk write operations, the application runs the risk of having another application create a work item with the same name before the call to **IPersistFile::Save** is made.

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[ITaskScheduler](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itaskscheduler)

[ITaskScheduler::NewWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itaskscheduler-newworkitem)