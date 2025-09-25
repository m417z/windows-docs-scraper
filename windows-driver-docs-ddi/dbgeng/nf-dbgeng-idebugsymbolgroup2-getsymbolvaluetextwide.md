# IDebugSymbolGroup2::GetSymbolValueTextWide

## Description

The **GetSymbolValueTextWide** method returns a string that represents the value of a symbol.

## Parameters

### `Index` [in]

The index of the symbol whose value you want. The index of a symbol is an identification number. The index ranges from zero through the number of symbols in the symbol group minus one.

### `Buffer` [out, optional]

The value of the symbol as a string. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

The size, in characters, of the *Buffer* buffer. This size includes the space for the '\0' terminating character.

### `NameSize` [out, optional]

The size, in characters, of the value of the symbol. This size includes the space for the '\0' terminating character. If *NameSize* is **NULL**, this information is not returned.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the value of the symbol would not fit in the buffer referred to by the *Buffer* parameter, so a truncated value was returned. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

If you added the symbol to the symbol group by using the [AddSymbol](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-addsymbol) method, the string that is returned to *Buffer* is the name of the symbol that is passed to **AddSymbol**.

For more information about symbol groups, see [Scopes and Symbol Groups](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups).

## See also

[GetNumberSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-getnumbersymbols)

[IDebugSymbolGroup2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbolgroup2)

[WriteSymbol](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-writesymbol)