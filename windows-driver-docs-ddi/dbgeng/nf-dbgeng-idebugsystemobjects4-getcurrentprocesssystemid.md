# IDebugSystemObjects4::GetCurrentProcessSystemId

## Description

The **GetCurrentProcessSystemId** method returns the system process ID of the current process.

## Parameters

### `SysId` [out]

Receives the system process ID.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOTIMPL** | The target is a kernel-mode target. |

## Remarks

This method is only available in user-mode debugging.

For more information about processes, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes).