# IScheduledWorkItem::GetIdleWait

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Retrieves the [idle wait time](https://learn.microsoft.com/windows/desktop/TaskSchd/i) for the work item.
For information about idle conditions, see [Task Idle Conditions](https://learn.microsoft.com/windows/desktop/TaskSchd/task-idle-conditions).

## Parameters

### `pwIdleMinutes` [out]

A pointer to a **WORD** that contains the idle wait time for the current work item, in minutes.

### `pwDeadlineMinutes` [out]

A pointer to a **WORD** that specifies the maximum number of minutes that the Task Scheduler will wait for the idle-time period returned in *pwIdleMinutes*.

## Return value

The
**GetIdleWait** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |

## Remarks

The idle time returned here is used in conjunction with [idle triggers](https://learn.microsoft.com/windows/desktop/TaskSchd/i) and [idle conditions](https://learn.microsoft.com/windows/desktop/TaskSchd/i). Idle triggers are event-based triggers that are not associated with a scheduled time. Idle conditions are associated with the scheduled start time for the task.

Idle triggers are specified by setting the
[TASK_TRIGGER_TYPE](https://learn.microsoft.com/windows/desktop/api/mstask/ne-mstask-task_trigger_type) member of the
[TASK_TRIGGER](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-task_trigger) structure to the value TASK_EVENT_TRIGGER_ON_IDLE. The idle trigger is fired when the system becomes idle for the amount of time returned in *pwIdleMinutes*.

You can set idle conditions by calling
[IScheduledWorkItem::SetFlags](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setflags). If the TASK_FLAG_START_ONLY_IF_IDLE flag is set, the work item runs at its scheduled time only if the system becomes idle for the amount of time returned in *pwIdleMinutes*. The Task Scheduler service will wait up to *pwDeadlineMinutes* past the scheduled start time to see if the system becomes idle.

#### Examples

For an example of how to retrieve the idle wait time of a task, see [C/C++ Code Example: Retrieving Task Idle-wait Time](https://learn.microsoft.com/windows/desktop/TaskSchd/c-c-code-example-retrieving-task-idle-wait-time).

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[IScheduledWorkItem::SetIdleWait](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setidlewait)