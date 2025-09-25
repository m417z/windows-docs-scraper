# IDebugSymbolGroup2::GetSymbolSize

## Description

The **GetSymbolSize** method returns the size of a symbol's value.

## Parameters

### `Index` [in]

The index of the symbol to remove. The index of a symbol is an identification number. The index ranges from zero through the number of symbols in the symbol group minus one.

### `Size` [out]

The size, in bytes, of the symbol's value. This information might not be available. If this information is not available, *Size* is set to zero. For some symbols (for example, a function's code), the data might be split over multiple regions. In this situation, *Size* is not meaningful.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOINTERFACE** | The symbol does not have type data associated with it. |

This method can also return other error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

For more information about symbol groups, see [Scopes and Symbol Groups](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups).

## See also

[GetNumberSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-getnumbersymbols)

[IDebugSymbolGroup2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbolgroup2)

[IDebugSymbols::GetTypeSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-gettypesize)