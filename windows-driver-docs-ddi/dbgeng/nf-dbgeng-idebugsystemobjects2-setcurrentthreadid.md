# IDebugSystemObjects2::SetCurrentThreadId

## Description

The **SetCurrentThreadId** method makes the specified thread the current thread.

## Parameters

### `Id` [in]

Specifies the engine thread ID of the thread that is to become the current thread.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOINTERFACE** | No thread with the specified ID was found. |

## Remarks

This method may also change the current process, current target, and current computer.

If the thread is changed, the callback [IDebugEventCallbacks::ChangeEngineState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-changeenginestate) will be called with the DEBUG_CES_CURRENT_THREAD bit set.

**Note** In kernel-mode debugging, the current thread is a virtual thread, it is not a system thread. This method cannot be used to change between system threads in kernel-mode debugging. However, the implicit thread may be changed by using [SetImplicitThreadDataOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsystemobjects4-setimplicitthreaddataoffset).

For more information about threads, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes). For details on monitoring events, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events).