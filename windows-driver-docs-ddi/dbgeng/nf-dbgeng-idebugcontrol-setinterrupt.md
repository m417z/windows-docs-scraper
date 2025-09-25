# IDebugControl::SetInterrupt

## Description

The **SetInterrupt** method registers a user interrupt or breaks into the debugger.

## Parameters

### `Flags` [in]

Specifies the type of interrupt to register. *Flags* can take one of the values listed in the following table.

| Value | Description |
| --- | --- |
| DEBUG_INTERRUPT_ACTIVE | If the target is running, the engine will request a break into the debugger. This request might time out. For more information, see the "Remarks" section.<br><br>Otherwise, when the target is suspended, the engine will register a user interrupt. |
| DEBUG_INTERRUPT_PASSIVE | The engine will register a user interrupt. |
| DEBUG_INTERRUPT_EXIT | If there is currently a [WaitForEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-waitforevent) call running, the engine will force it to return. If there are any debugger commands causing execution in the target -- for example, [g (Go)](https://learn.microsoft.com/windows-hardware/drivers/debugger/g--go-) and [p (Step)](https://learn.microsoft.com/windows-hardware/drivers/debugger/p--step-) -- the engine will force them to complete. This does not force a break into the debugger, so the target might not be suspended. In which case, the **WaitForEvent** call will return E_PENDING.<br><br>Otherwise, when the target is suspended, register a user interrupt. |

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method can be called at any time and from any thread. Once the interrupt has been registered, this method returns immediately.

If *Flags* is DEBUG_INTERRUPT_ACTIVE, and the interrupt times out, the engine will generate a synthetic exception event. This event will be sent to event callback's [IDebugEventCallbacks::Exception](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-exception) method. The amount of time before the interrupt times out can be set using [SetInterruptTimeout](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setinterrupttimeout).

## See also

[GetInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getinterrupt)

[GetInterruptTimeout](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getinterrupttimeout)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[SetInterruptTimeout](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setinterrupttimeout)