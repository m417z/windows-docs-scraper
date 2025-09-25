# IDebugSystemObjects::GetCurrentThreadHandle

## Description

The **GetCurrentThreadHandle** method returns the system handle for the current thread.

## Parameters

### `Handle` [out]

Receives the current thread's system handle.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

In kernel-mode debugging, an artificial handle is created because the threads are virtual threads.

For more information about threads, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes). For details on system handles, see [Handles](https://learn.microsoft.com/windows-hardware/drivers/).