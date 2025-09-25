# IDebugSymbols2::StartSymbolMatch

## Description

The **StartSymbolMatch** method initializes a search for symbols whose names match a given pattern.

## Parameters

### `Pattern` [in]

Specifies the pattern for which to search. The search will return all symbols whose names match this pattern. For details of the syntax of the pattern, see [Symbol Syntax and Symbol Matching](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbol-syntax-and-symbol-matching) and [String Wildcard Syntax](https://learn.microsoft.com/windows-hardware/drivers/debugger/string-wildcard-syntax).

### `Handle` [out]

Receives the handle identifying the search. This handle can be passed to [GetNextSymbolMatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getnextsymbolmatch) and [EndSymbolMatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-endsymbolmatch).

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOINTERFACE** | The specified module was not found. |

## Remarks

This method initializes a symbol search. The results of the search can be obtained by repeated calls to [GetNextSymbolMatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getnextsymbolmatch). When all the desired results have been found, use [EndSymbolMatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-endsymbolmatch) to release resources the engine holds for the search.

For more information about symbols, see [Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4).

## See also

[EndSymbolMatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-endsymbolmatch)

[GetNextSymbolMatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getnextsymbolmatch)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)