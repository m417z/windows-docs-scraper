# IDebugSystemObjects::GetCurrentThreadSystemId

## Description

The **GetCurrentThreadSystemId** method returns the system thread ID of the current thread.

## Parameters

### `SysId` [out]

Receives the system thread ID.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOTIMPL** | The target is a kernel-mode target. |

## Remarks

This method is only available in user-mode debugging.

For more information about threads, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes).