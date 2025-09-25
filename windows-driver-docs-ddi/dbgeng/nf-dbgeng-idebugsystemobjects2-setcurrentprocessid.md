# IDebugSystemObjects2::SetCurrentProcessId

## Description

The **SetCurrentProcessId** method makes the specified process the current process.

## Parameters

### `Id` [in]

Specifies the engine process ID for the process that is to become the current process.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOINTERFACE** | No process with the given process ID was found. |
| **E_FAIL** | No suitable candidate for the current thread could be found in the process. |

## Remarks

This method also changes the current thread, and may change the current target and current computer.

If the process is changed, the callback [IDebugEventCallbacks::ChangeEngineState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-changeenginestate) will be called with the DEBUG_CES_CURRENT_THREAD bit set.

**Note** In kernel-mode debugging, the current process is a virtual process, it is not a system process. This method cannot be used to change between system processes in kernel-mode debugging. However, the implicit process may be changed by using [SetImplicitProcessDataOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsystemobjects4-setimplicitprocessdataoffset).

For more information about processes, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes). For details on monitoring events, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events).