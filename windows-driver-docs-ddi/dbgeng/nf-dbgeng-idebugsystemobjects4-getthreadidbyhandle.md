# IDebugSystemObjects4::GetThreadIdByHandle

## Description

The **GetThreadIdByHandle** method returns the engine thread ID for the specified thread. The thread is specified by its system handle.

## Parameters

### `Handle` [in]

Specifies the system handle of the thread whose thread ID is requested.

### `Id` [out]

Receives the engine thread ID.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

In kernel-mode debugging, because the handle is an artificial handle for a processor, this method returns the engine thread ID for the virtual thread representing that processor.

For more information about threads, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes). For details on system handles, see [Handles](https://learn.microsoft.com/windows-hardware/drivers/).