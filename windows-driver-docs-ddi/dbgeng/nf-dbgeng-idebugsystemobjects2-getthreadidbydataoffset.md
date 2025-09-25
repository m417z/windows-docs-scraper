# IDebugSystemObjects2::GetThreadIdByDataOffset

## Description

The **GetThreadIdByDataOffset** method returns the engine thread ID for the specified thread. The thread is specified by its system data structure.

## Parameters

### `Offset` [in]

Specifies the location of the system data structure for the thread.

### `Id` [out]

Receives the engine thread ID.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

In kernel-mode debugging, this method returns the engine thread ID for the virtual thread representing the processor on which the specified thread is executing. If the thread is not executing on a processor, this method will fail.

For more information about threads, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes).