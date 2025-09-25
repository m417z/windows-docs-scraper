# IDebugSystemObjects4::GetProcessIdByPeb

## Description

The **GetProcessIdByPeb** method returns the engine process ID for the specified process. The process is specified by its process environment block (PEB).

## Parameters

### `Offset` [in]

Specifies the location in the target's virtual address space of the PEB of the process whose process ID is requested.

### `Id` [out]

Receives the engine process ID.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOTIMPL** | The target is a kernel-mode target. This method is currently not available in kernel-mode debugging. |

## Remarks

This method is not available in kernel-mode debugging.

For more information about processes, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes).