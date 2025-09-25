# ITaskScheduler::Activate

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

The
**Activate** method returns an active interface for a specified [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w).

## Parameters

### `pwszName` [in]

A null-terminated string that specifies the name of the work item to activate.

### `riid` [in]

An identifier that identifies the interface being requested. The only interface supported at this time,
[ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask), has the identifier IID_ITask.

### `ppUnk` [out]

A pointer to an interface pointer that receives the address of the requested interface.

## Return value

When
this method succeeds, S_OK is returned.

If the method fails, one of the following error codes may be returned.

| Return code | Description |
| --- | --- |
| **COR_E_FILENOTFOUND** | The task does not exist. |
| **E_INVALIDARG** | The *pwszName* parameter is not valid. |
| **E_OUTOFMEMORY** | A memory allocation failed. |
| **SCHED_E_UNKNOWN_OBJECT_VERSION** | The task object version is either unsupported or invalid. |

## See also

[ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask)

[ITaskScheduler](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itaskscheduler)