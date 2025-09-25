# IScheduledWorkItem::GetExitCode

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Retrieves the last exit code returned by the executable associated with the [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w) on its last run. The method also returns the exit code returned to Task Scheduler when it last attempted to run the work item.

## Parameters

### `pdwExitCode` [out]

A pointer to a **DWORD** value that is set to the last exit code for the work item. This is the exit code that the work item returned when it last stopped running. If the work item has never been started, 0 is returned.

## Return value

The
**GetExitCode** method returns the error from the last attempt to start the work item. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The attempt to start the work item was successful. |
| **SCHED_S_TASK_HAS_NOT_RUN** | No attempt has ever been made to start this work item. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## Remarks

This method can return the following two pieces of information:

* The error or exit code that is returned by the executable that is being scheduled is returned in the *pdwExitCode* parameter.
* The error code that the Task Scheduler received when it tried to start the job is returned in the
  **GetExitCode** method call itself.

To obtain an updated error code, always call [ITaskScheduler::Activate](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-itaskscheduler-activate) first to obtain a new [IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem) interface, which can then be used to obtain the updated error codes.

#### Examples

For an example of how to retrieve the creator of a task, see [C/C++ Code Example: Retrieving Task Exit Code](https://learn.microsoft.com/windows/desktop/TaskSchd/c-c-code-example-retrieving-task-exit-code).

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)