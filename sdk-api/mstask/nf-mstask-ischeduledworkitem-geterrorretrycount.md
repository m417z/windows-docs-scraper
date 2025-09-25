# IScheduledWorkItem::GetErrorRetryCount

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Retrieves the number of times that the Task Scheduler will retry an operation when an error occurs. This method is not implemented.

## Parameters

### `pwRetryCount` [out]

A pointer to a **WORD** that contains the number of times to retry.

## Return value

Not implemented.

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[SetErrorRetryCount](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-seterrorretrycount)