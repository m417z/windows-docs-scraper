# IScheduledWorkItem::SetIdleWait

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Sets the minutes that the system must be idle before the [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w) can run.

## Parameters

### `wIdleMinutes` [in]

A value that specifies how long, in minutes, the system must remain idle before the work item can run.

### `wDeadlineMinutes` [in]

A value that specifies the maximum number of minutes that the Task Scheduler will wait for the idle-time period returned in *pwIdleMinutes*.

## Return value

The
**SetIdleWait** method returns S_OK.

## Remarks

The idle time specified here is used in conjunction with [idle triggers](https://learn.microsoft.com/windows/desktop/TaskSchd/i) and [idle conditions](https://learn.microsoft.com/windows/desktop/TaskSchd/i). For more information, see [Task Idle Conditions](https://learn.microsoft.com/windows/desktop/TaskSchd/task-idle-conditions). Idle triggers are event-based triggers that are not associated with a scheduled time. Idle conditions, in contrast, are associated with the scheduled start time for the task.

You specify idle triggers by setting the TASK_TRIGGER_TYPE member of the
[TASK_TRIGGER](https://learn.microsoft.com/windows/desktop/api/mstask/ns-mstask-task_trigger) to TASK_EVENT_TRIGGER_ON_IDLE. The idle trigger is fired when the system becomes idle for the amount of time specified by *wIdleMinutes*.

You set idle conditions by calling
[IScheduledWorkItem::SetFlags](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setflags). If the TASK_FLAG_START_ONLY_IF_IDLE flag is set, the work item runs at its scheduled time only if the system becomes idle for the amount of time specified by *wIdleMinutes*. The Task Scheduler service will wait up to the number of minutes specified in *wDeadlineMinutes* past the scheduled start time to see if the system becomes idle.

Applications must call the **IPersistFile::Save** method after calling
**SetIdleWait** to update the idle wait interval.

#### Examples

For an example of how to set the idle wait time when creating an idle trigger, see [Creating an Idle Trigger Example](https://learn.microsoft.com/windows/desktop/TaskSchd/creating-an-idle-trigger-example).

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[IScheduledWorkItem::GetIdleWait](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-getidlewait)