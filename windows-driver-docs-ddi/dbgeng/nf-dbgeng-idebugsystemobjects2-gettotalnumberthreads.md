# IDebugSystemObjects2::GetTotalNumberThreads

## Description

The **GetTotalNumberThreads** method returns the total number of [threads](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-threads-and-processes) for all the [processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-threads-and-processes) in the current target, in addition to the largest number of threads in any process for the current target.

## Parameters

### `Total` [out]

Receives the total number of threads for all the processes in the current target.

### `LargestProcess` [out]

Receives the largest number of threads in any process for the current target.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information about threads, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes).