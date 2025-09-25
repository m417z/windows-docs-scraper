# IDebugSystemObjects4::GetEventSystem

## Description

The **GetEventSystem** method returns the engine target ID for the target in which the last event occurred.

## Parameters

### `Id` [out]

Receives the engine target ID.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## See also

[Debugging Session and Execution Model](https://learn.microsoft.com/windows-hardware/drivers/debugger/debugging-session-and-execution-model)

[IDebugSystemObjects3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsystemobjects3)

[IDebugSystemObjects4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsystemobjects4)

[Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events)