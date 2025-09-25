# IDebugSystemObjects3::SetCurrentSystemId

## Description

The **SetCurrentSystemId** method makes the specified target the current target.

## Parameters

### `Id` [in]

Specifies the engine target ID for the target that is to become the current target.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOINTERFACE** | No process with the given ID was found. |

## Remarks

This method also sets the current thread and current process, and may change the current computer.

If the current target is changed, the callback [IDebugEventCallbacks::ChangeEngineState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-changeenginestate) will be called with the DEBUG_CES_CURRENT_THREAD bit set.

## See also

[Debugging Session and Execution Model](https://learn.microsoft.com/windows-hardware/drivers/debugger/debugging-session-and-execution-model)

[IDebugSystemObjects3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsystemobjects3)

[IDebugSystemObjects4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsystemobjects4)

[Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events)