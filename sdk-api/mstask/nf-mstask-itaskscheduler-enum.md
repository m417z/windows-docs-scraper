# ITaskScheduler::Enum

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

The
**Enum** method retrieves a pointer to an OLE enumerator object that enumerates the tasks in the current task folder.

## Parameters

### `ppEnumWorkItems` [out]

A pointer to a pointer to an
[IEnumWorkItems](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ienumworkitems) interface. This interface contains the enumeration context of the current task(s).

## Return value

The
**Enum** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## Remarks

By default, the current folder resides on the local computer. For remote computers, call
[ITaskScheduler::GetTargetComputer](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itaskscheduler-gettargetcomputer) and use the name returned by this call. To change the target computer call
[ITaskScheduler::SetTargetComputer](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itaskscheduler-settargetcomputer).

| For a complete example of | See |
| --- | --- |
| Using **Enum** to retrieve the task names on the local computer | [Enumerating Tasks Example](https://learn.microsoft.com/windows/desktop/TaskSchd/enumerating-tasks-example) |

## See also

[IEnumWorkItems](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ienumworkitems)

[ITaskScheduler](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itaskscheduler)

[ITaskScheduler::GetTargetComputer](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itaskscheduler-gettargetcomputer)

[ITaskScheduler::SetTargetComputer](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itaskscheduler-settargetcomputer)