## Description

The CreateThread callback method is called by the engine when a create-threaddebugging event occurs in the target.

Any of these values can be zero if they cannot be provided by the engine.
Currently the kernel does not return thread or process change events.

Refer to [IDebugEventCallbacks::CreateThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-createthread) for parameter description and additional information.

## Parameters

### `Handle`

### `DataOffset`

### `StartOffset`

### `Context` [in]

Specifies the [DEBUG_EVENT_CONTEXT structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_event_context) as the “context” parameter of each event callback. The context structure contains additional information about the debug event that occurred.

### `ContextSize` [in]

Specifies the size of the buffer Context.

## Return value

## Remarks

## See also

[IDebugEventContextCallbacks (dbgeng.h)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugeventcontextcallbacks)