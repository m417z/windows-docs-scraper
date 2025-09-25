## Description

The LoadModule callback method is called by the engine when a module-load debugging event occurs in the target.

Refer to [IDebugEventCallbacks::LoadModule](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-loadmodule) for parameter description and additional information.

## Parameters

Any of these values may be zero.

### `ImageFileHandle`

### `BaseOffset`

### `ModuleSize`

### `ModuleName`

### `ImageName`

### `CheckSum`

### `TimeDateStamp`

### `Context` [in]

Specifies the [DEBUG_EVENT_CONTEXT structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_event_context) as the “context” parameter of each event callback. The context structure contains additional information about the debug event that occurred.

### `ContextSize` [in]

Specifies the size of the buffer Context.

## Return value

## Remarks

## See also

[IDebugEventContextCallbacks (dbgeng.h)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugeventcontextcallbacks)