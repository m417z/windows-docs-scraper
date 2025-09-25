# IDebugSystemObjects3::GetCurrentThreadId

## Description

The **GetCurrentThreadId** method returns the engine thread ID for the current thread.

## Parameters

### `Id` [out]

Receives the engine thread ID.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information about threads, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes).