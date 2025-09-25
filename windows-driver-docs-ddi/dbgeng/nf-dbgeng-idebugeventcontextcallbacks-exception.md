## Description

The Exception callback method is called by the engine when an exception debugging event occurs in the target.

Exceptions include breaks which cannot be mapped to an existing breakpoint instance.

Refer to [IDebugEventCallbacks::Exception](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-exception) for parameter description and additional information.

## Parameters

### `Exception`

### `FirstChance`

### `Context` [in]

Specifies the [DEBUG_EVENT_CONTEXT structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_event_context) as the “context” parameter of each event callback. The context structure contains additional information about the debug event that occurred.

### `ContextSize` [in]

Specifies the size of the buffer Context.

## Return value

## Remarks

## See also

[IDebugEventContextCallbacks (dbgeng.h)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugeventcontextcallbacks)