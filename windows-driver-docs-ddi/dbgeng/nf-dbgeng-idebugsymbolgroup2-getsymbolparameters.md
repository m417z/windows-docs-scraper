# IDebugSymbolGroup2::GetSymbolParameters

## Description

The **GetSymbolParameters** method returns the symbol parameters that describe the specified [symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4) in a symbol group.

## Parameters

### `Start` [in]

The index in the symbol group of the first symbol whose parameters you want. The index of a symbol is an identification number. This number ranges from zero through the number of symbols in the symbol group minus one.

### `Count` [in]

The number of symbol parameters that you want.

### `Params` [out]

The symbol parameters. This array must hold at least *Count* elements. For a description of these parameters, see [DEBUG_SYMBOL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_symbol_parameters).

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

For more information about symbol groups, see [Scopes and Symbol Groups](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups).

## See also

[DEBUG_SYMBOL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_symbol_parameters)

[GetNumberSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-getnumbersymbols)

[IDebugSymbolGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbolgroup)

[IDebugSymbolGroup2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbolgroup2)