## Description

The **ExitProcess** callback method is called by the engine when an exit-process debugging event occurs in the target.

Refer to [IDebugEventCallbacks::ExitProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-exitprocess) for parameter description and additional information.

## Parameters

### `ExitCode`

### `Context` [in]

Specifies the [DEBUG_EVENT_CONTEXT structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_event_context) as the “context” parameter of each event callback. The context structure contains additional information about the debug event that occurred.

### `ContextSize` [in]

Specifies the size of the buffer Context.

## Return value

## Remarks

## See also

[IDebugEventContextCallbacks (dbgeng.h)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugeventcontextcallbacks)