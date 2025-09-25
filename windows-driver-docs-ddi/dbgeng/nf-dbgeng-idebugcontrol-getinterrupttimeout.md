# IDebugControl::GetInterruptTimeout

## Description

The **GetInterruptTimeout** method returns the number of seconds that the engine will wait when requesting a break into the debugger.

## Parameters

### `Seconds` [out]

Receives the number of seconds that the engine will wait for the target when requesting a break into the debugger.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The engine requests a break into the debugger when [SetInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setinterrupt) is called with DEBUG_INTERRUPT_ACTIVE. If this interrupt times out, the engine will generate a synthetic exception event. This event will be sent to [event callback objects](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-callback-objects)'s [IDebugEventCallbacks::Exception](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-exception) method.

Most targets do not support interrupt time-outs. Live user-mode debugging is one of the targets that does support them.

## See also

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[IDebugEventCallbacks::Exception](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-exception)

[SetInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setinterrupt)

[SetInterruptTimeout](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setinterrupttimeout)