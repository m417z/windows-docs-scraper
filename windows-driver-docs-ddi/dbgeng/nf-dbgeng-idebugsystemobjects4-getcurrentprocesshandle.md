# IDebugSystemObjects4::GetCurrentProcessHandle

## Description

The **GetCurrentProcessHandle** method returns the system handle for the current process.

## Parameters

### `Handle` [out]

Receives the system handle of the current process.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

In kernel-mode debugging, the only process in the target is the virtual process created for the kernel. In this case, an artificial handle is created. The artificial handle can only be used with the debugger engine API.

For more information about processes, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes). For details on system handles, see [Handles](https://learn.microsoft.com/windows-hardware/drivers/).