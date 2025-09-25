# IDebugSystemObjects::GetEventThread

## Description

The **GetEventThread** method returns the engine thread ID for the thread on which the last event occurred.

## Parameters

### `Id` [out]

Receives the engine thread ID.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

In kernel-mode debugging, the engine thread ID for the virtual thread representing the processor on which the event occurred is returned.

For more information about threads, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes). For details about debugger engine events, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events).