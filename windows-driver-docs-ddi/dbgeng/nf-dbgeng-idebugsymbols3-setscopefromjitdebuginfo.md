# IDebugSymbols3::SetScopeFromJitDebugInfo

## Description

Recovers just-in-time (JIT) debugging information and sets current
debugger scope context based on that information.

## Parameters

### `OutputControl` [in]

An output control.

### `InfoOffset` [in]

An offset for the debugging information.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

The method gets JUT debugging information from a specified address from the debugging target, and then sets the current
debugger scope context from that information.

This method is equivalent to '.jdinfo' command.

## See also

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)