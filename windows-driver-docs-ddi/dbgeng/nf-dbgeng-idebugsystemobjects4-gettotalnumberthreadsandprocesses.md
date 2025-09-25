# IDebugSystemObjects4::GetTotalNumberThreadsAndProcesses

## Description

The **GetTotalNumberThreadsAndProcesses** method returns the total number of [threads](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-threads-and-processes) and [processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-threads-and-processes) in all the targets the engine is attached to, in addition to the largest number of threads and processes in a target.

## Parameters

### `TotalThreads` [out]

Receives the total number of threads in all processes in all targets.

### `TotalProcesses` [out]

Receives the total number of processes in all targets.

### `LargestProcessThreads` [out]

Receives the largest number of threads in any process on any target.

### `LargestSystemThreads` [out]

Receives the largest number of threads in any target.

### `LargestSystemProcesses` [out]

Receives the largest number of processes in any target.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

If no target is found, all the values are set to zero.

## See also

[IDebugSystemObjects3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsystemobjects3)

[IDebugSystemObjects4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsystemobjects4)

[Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes)