## Description

The UnloadModule callback method is called by the engine when a module-unload debugging event occurs in the target.

Refer to [IDebugEventCallbacks::UnloadModule](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-unloadmodule) for parameter description and additional information.

## Parameters

### `ImageBaseName`

### `BaseOffset`

### `Context` [in]

Specifies the [DEBUG_EVENT_CONTEXT structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_event_context) as the “context” parameter of each event callback. The context structure contains additional information about the debug event that occurred.

### `ContextSize` [in]

Specifies the size of the buffer Context.

## Return value

## Remarks

## See also

[IDebugEventContextCallbacks (dbgeng.h)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugeventcontextcallbacks)