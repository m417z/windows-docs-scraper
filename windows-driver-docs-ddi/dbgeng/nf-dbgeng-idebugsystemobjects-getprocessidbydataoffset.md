# IDebugSystemObjects::GetProcessIdByDataOffset

## Description

The **GetProcessIdByDataOffset** method returns the engine process ID for the specified process. The process is specified by its data offset.

## Parameters

### `Offset` [in]

Specifies the location in the target's virtual address space of the data offset of the process.

### `Id` [out]

Receives the engine process ID for the process.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOTIMPL** | The current target is a kernel-mode target. This method is currently not available in kernel-mode debugging. |

## Remarks

This method is currently not available in kernel-mode debugging.

In user-mode debugging, this method behaves the same as [GetProcessIdByPeb](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsystemobjects4-getprocessidbypeb).

For more information about processes, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes).