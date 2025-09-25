## Description

The CreateProcess callback method is called by the engine when a create-process debugging event occurs in the target.

Any of these values can be zero if they cannot be provided by the engine.

Refer to [IDebugEventCallbacks::CreateProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-createprocess) for parameter description and additional information.

## Parameters

### `ImageFileHandle`

### `Handle`

### `BaseOffset`

### `ModuleSize`

### `ModuleName`

### `ImageName`

### `CheckSum`

### `TimeDateStamp`

### `InitialThreadHandle`

### `ThreadDataOffset`

### `StartOffset`

### `Context` [in]

Specifies the [DEBUG_EVENT_CONTEXT structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_event_context) as the “context” parameter of each event callback. The context structure contains additional information about the debug event that occurred.

### `ContextSize` [in]

Specifies the size of the buffer Context.

## Return value

## Remarks

## See also

[IDebugEventContextCallbacks (dbgeng.h)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugeventcontextcallbacks)