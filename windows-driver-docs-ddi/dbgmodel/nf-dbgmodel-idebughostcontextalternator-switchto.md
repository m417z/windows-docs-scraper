## Description

The SwitchTo method changes or switches the debugger engine context to the IDebugHostContext from which the IDebugHostContextControl was retrieved. Unlike a full context switch, this change is temporary, and not all debugger functionalities may be available or may work as expected unless the context is switched back.

## Parameters

### `fullSwitch`

A boolean value that indicates whether the switch should be a "full" context switch. If set to true, it indicates a complete switch to the new context, while false indicates a temporary switch.

## Return value

## Remarks

It allows for transitioning between different debugging contexts without committing to a permanent switch. This feature is useful in scenarios where developers want to test or inspect a particular context without losing the original debugging state.

## See also

- [IDebugHostContextAlternator interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostcontextalternator)
- [IDebugHostContextControl interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostcontextcontrol)
- [IDebugHostContext interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostcontext)