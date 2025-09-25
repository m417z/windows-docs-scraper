# IDebugSymbols3::GetSymbolEntryByToken

## Description

Looks up a symbol by using a managed metadata token.

## Parameters

### `ModuleBase` [in]

The base of the module.

### `Token` [in]

The token to use to look up the symbol.

### `Id` [out]

A pointer to the module as a [DEBUG_MODULE_AND_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_module_and_id) structure.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DEBUG_MODULE_AND_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_module_and_id)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)