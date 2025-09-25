# IScheduledWorkItem::GetStatus

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Retrieves the status of the [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w).

## Parameters

### `phrStatus` [out]

A pointer to an **HRESULT** value that contains one of the following values on return.

#### SCHED_S_TASK_READY

The work item is ready to run at its next scheduled time.

#### SCHED_S_TASK_RUNNING

The work item is currently running.

#### SCHED_S_TASK_NOT_SCHEDULED

One or more of the properties that are needed to run this task on a schedule have not been set.

#### SCHED_S_TASK_HAS_NOT_RUN

The task has not been run. This value is returned whenever the task has not been run, even if the task is ready to be run at the next scheduled time or the task is a recurring task.

#### SCHED_S_TASK_DISABLED

The task will not run at the scheduled times because it has been disabled.

#### SCHED_S_TASK_NO_MORE_RUNS

There are no more runs scheduled for this task.

#### SCHED_S_TASK_NO_VALID_TRIGGERS

Either the task has no triggers or the existing triggers are disabled or not set.

## Return value

The
**GetStatus** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. The request was sent. For more information, see Remarks. |
| **E_INVALIDARG** | The arguments are not valid. |

## Remarks

The methods of the
[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem) interface are inherited by the
[ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask) interface. Consequently,
**IScheduledWorkItem::GetStatus** is typically called through the
**ITask** interface.

**IScheduledWorkItem::GetStatus** does not obtain the status of the task dynamically. [ITaskScheduler::Activate](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itaskscheduler-activate) should be called to obtain a new [IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem) interface, which is used to get an updated status. For more information, see the example for [ITaskScheduler::Activate](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itaskscheduler-activate).

#### Examples

For an example of how to retrieve the status of a task, see [C/C++ Code Example: Retrieving Task Status](https://learn.microsoft.com/windows/desktop/TaskSchd/c-c-code-example-retrieving-task-status).

For an example of how to retrieve the task status as part of terminating the task, see [Terminating a Task Example](https://learn.microsoft.com/windows/desktop/TaskSchd/terminating-a-task-example).

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[ITask](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itask)