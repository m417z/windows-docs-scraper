# IDebugSymbols3::GetScopeSymbolGroup2

## Description

The **GetScopeSymbolGroup2** method returns a symbol group containing the symbols in the current target's scope.

## Parameters

### `Flags` [in]

Specifies a bit-set used to determine which symbols to include in the symbol group. To include all symbols, set *Flags* to DEBUG_SCOPE_GROUP_ALL. The following bit-flags determine which symbols are included.

| Flag | Description |
| --- | --- |
| DEBUG_SCOPE_GROUP_ARGUMENTS | Include the function arguments for the current scope. |
| DEBUG_SCOPE_GROUP_LOCALS | Include the local variables for the current scope. |

### `Update` [in, optional]

Specifies a previously created symbol group that will be updated to reflect the current scope. If *Update* is **NULL**, a new symbol group interface object is created.

### `Symbols` [out]

Receives the symbol group interface object for the current scope. For details on this interface, see [IDebugSymbolGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbolgroup)

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The *Update* parameter allows for efficient updates when stepping through code. Instead of creating and populating a new symbol group, the old symbol group can be updated.

For more information about scopes and symbol groups, see [Scopes and Symbol Groups](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups).

## See also

[GetScope](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getscope)

[IDebugSymbolGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbolgroup)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)