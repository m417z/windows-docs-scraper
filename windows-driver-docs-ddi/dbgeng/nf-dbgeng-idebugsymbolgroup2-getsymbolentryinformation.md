# IDebugSymbolGroup2::GetSymbolEntryInformation

## Description

The **GetSymbolEntryInformation** method returns information about a symbol in a symbol group.

## Parameters

### `Index` [in]

The index of the symbol whose information you want. The index of a symbol is an identification number. The index ranges from zero through the number of symbols in the symbol group minus one.

### `Entry` [out]

The information about the symbol. For more information about this structure, see [DEBUG_SYMBOL_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_symbol_entry).

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

For more information about symbol groups, see [Scopes and Symbol Groups](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups).

## See also

[DEBUG_SYMBOL_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_symbol_entry)

[GetNumberSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-getnumbersymbols)

[IDebugSymbolGroup2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbolgroup2)

[IDebugSymbols3::GetSymbolEntryInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getsymbolentryinformation)