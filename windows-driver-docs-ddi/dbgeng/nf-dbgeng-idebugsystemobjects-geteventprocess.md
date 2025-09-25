# IDebugSystemObjects::GetEventProcess

## Description

The **GetEventProcess** method returns the engine process ID for the process on which the last event occurred.

## Parameters

### `Id` [out]

Receives the engine process ID.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

In kernel-mode debugging, the engine process ID for the virtual process representing the kernel is returned.

For more information about processes, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes). For details about debugger engine events, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events).