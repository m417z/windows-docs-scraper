# IDebugSymbols3::GetSymbolEntryInformation

## Description

The **GetSymbolEntryInformation** method returns the symbol entry information for a symbol.

## Parameters

### `Id` [in]

Specifies the module and symbol ID of the desired symbol. For details on this structure, see [DEBUG_MODULE_AND_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_module_and_id).

### `Info` [out]

Receives the symbol entry information for the symbol. For details on this structure, see [DEBUG_SYMBOL_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_symbol_entry).

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For details on the symbol entry information, see [Scopes and Symbol Groups](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups).

## See also

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)

[IdebugSymbolGroup2::GetSymbolEntryInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-getsymbolentryinformation)