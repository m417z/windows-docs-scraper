## Description

Debuggee state, such as registers or data spaces, has changed.

This is an informational callback notifying the provider about changes in debug state. The return value of this callbacks is ignored. Implementations can't call back into the engine.

Refer to [IDebugEventCallbacks::ChangeDebuggeeState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-changedebuggeestate) for parameter description and additional information.

## Parameters

### `Flags`

### `Argument`

### `Context` [in]

Specifies the [DEBUG_EVENT_CONTEXT structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_event_context) as the “context” parameter of each event callback. The context structure contains additional information about the debug event that occurred.

### `ContextSize` [in]

Specifies the size of the buffer Context.

## Return value

## Remarks

## See also

[IDebugEventContextCallbacks (dbgeng.h)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugeventcontextcallbacks)