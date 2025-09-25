# IDebugSystemObjects4::GetThreadIdBySystemId

## Description

The **GetThreadIdBySystemId** method returns the engine thread ID for the specified thread. The thread is specified by its system thread ID.

## Parameters

### `SysId` [in]

Specifies the system thread ID.

### `Id` [out]

Receives the engine thread ID.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOTIMPL** | The target is a kernel-mode target. |

## Remarks

This method is only available in user-mode debugging.

For more information about threads, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes).