## Description

The symbol state has changed.

This is an informational callback notifying the provider about changes in debug state. The return value of this callbacks is ignored. Implementations can't call back into the engine.

Refer to [IDebugEventCallbacks::ChangeSymbolState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-changesymbolstate) for parameter description and additional information.

## Parameters

### `Flags`

### `Argument`

## Return value

## Remarks

## See also

[IDebugEventContextCallbacks (dbgeng.h)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugeventcontextcallbacks)