# IDebugSystemObjects::GetNumberThreads

## Description

The **GetNumberThreads** method returns the number of [threads](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-threads-and-processes) in the current process.

## Parameters

### `Number` [out]

Receives the number of threads in the current process.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

In kernel-mode debugging, there is a virtual thread representing each processor.

In user-mode debugging, the number of threads changes with the [IDebugEventCallbacks::CreateThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-createthread) and [IDebugEventCallbacks::ExitThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-exitthread) events.

For more information about threads, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes).