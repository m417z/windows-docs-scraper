# IDebugEventCallbacksWide::Breakpoint

## Description

The **Breakpoint** callback method is called by the engine when the target issues a breakpoint[exception](https://learn.microsoft.com/windows-hardware/drivers/).

## Parameters

### `Bp` [in]

Specifies a pointer to the [IDebugBreakpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugbreakpoint) object corresponding to the breakpoint that was triggered.

## Return value

This method returns a [DEBUG_STATUS_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-status-xxx) value, which indicates how the execution of the target should proceed after the engine processes this event. For details on how the engine treats this value, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events).

## Remarks

If the breakpoint has an associated command, the engine executes that command before calling this method.

The engine will only call this method if an [IDebugBreakpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugbreakpoint) object corresponding to the breakpoint exists in the engine, and--if the breakpoint is a private breakpoint--this [IDebugEventCallbacksWide](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugeventcallbackswide) object was registered with the client that added the breakpoint.

The engine calls this method only if the DEBUG_EVENT_BREAKPOINT flag is set in the mask returned by [IDebugEventCallbacksWide::GetInterestMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbackswide-getinterestmask).

Because the engine deletes the corresponding **IDebugBreakpoint** object when a breakpoint is removed (for example, by using [RemoveBreakpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-removebreakpoint)), the value of *Bp* might be invalid after **Breakpoint** returns. Therefore, implementations of **IDebugEventCallbacksWide** should not access *Bp* after **Breakpoint** returns.

For more information about handling events, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events). For information about managing breakpoints, see [Breakpoints](https://learn.microsoft.com/windows-hardware/drivers/debugger/breakpoints3).