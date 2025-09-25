# IDebugControl::GetSystemErrorControl

## Description

The **GetSystemErrorControl** method returns the control values for handling system errors.

## Parameters

### `OutputLevel` [out]

Receives the level at which system errors are printed to the engine's output. If the level of the system error is less than or equal to *OutputLevel*, the error is printed to the debugger console.

### `BreakLevel` [out]

Receives the level at which system errors break into the debugger. If the level of the system error is less than or equal to *BreakLevel*, the error breaks into the debugger.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The level of a system error can take one of the following three values, listed from lowest to highest: SLE_ERROR, SLE_MINORERROR, and SLE_WARNING. These values are defined in Winuser.h.

When a system error occurs, the engine calls the [IDebugEventCallbacks::SystemError](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-systemerror) method of the event callbacks. If the level is less than or equal to *BreakLevel*, the error will break into the debugger. If the level is greater than *BreakLevel*, the engine will proceed with execution in the target as indicated by the **IDebugEventCallbacks::SystemError** method calls. For more information about how the engine proceeds after an event, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events).

## See also

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[IDebugEventCallbacks::SystemError](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-systemerror)

[SetSystemErrorControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setsystemerrorcontrol)