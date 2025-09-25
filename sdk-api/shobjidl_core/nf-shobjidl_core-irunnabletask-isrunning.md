# IRunnableTask::IsRunning

## Description

Requests information on the state of a task, such as thumbnail extraction.

## Return value

Type: **LONG**

Returns one of the following values to indicate the current execution state.

| Return code | Description |
| --- | --- |
| **IRTIR_TASK_NOT_RUNNING** | Extraction has not yet started. |
| **IRTIR_TASK_RUNNING** | The task is running. |
| **IRTIR_TASK_SUSPENDED** | The task is suspended. |
| **IRTIR_TASK_PENDING** | [IRunnableTask::Kill](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-irunnabletask-kill) has been called on the thread, but the thread has not yet completely shut down. |
| **IRTIR_TASK_FINISHED** | The task is finished. |

## Remarks

This method must be implemented.