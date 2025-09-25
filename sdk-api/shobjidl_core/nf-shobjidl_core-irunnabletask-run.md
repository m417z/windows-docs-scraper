# IRunnableTask::Run

## Description

Requests that a task begin.

## Return value

Type: **HRESULT**

Returns one of the following two codes.

| Return code | Description |
| --- | --- |
| **S_OK** | Execution is complete. |
| **E_PENDING** | Execution is suspended. |

## Remarks

The return value of this method only tells you whether the execution of the task completed or is suspended. Any other errors that the implementer needs to communicate to the caller must be provided through other channels, such as a callback function.