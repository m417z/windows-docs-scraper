# IDebugSystemObjects::GetNumberProcesses

## Description

The **GetNumberProcesses** method returns the number of [processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-threads-and-processes) for the current target.

## Parameters

### `Number` [out]

Receives the number of processes.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

In kernel-mode debugging, there is only a single virtual process representing the kernel.

In user-mode debugging, the number of processes changes with the create-process and exit-process debugging [events](https://learn.microsoft.com/windows-hardware/drivers/debugger/events).

For more information about processes, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes).