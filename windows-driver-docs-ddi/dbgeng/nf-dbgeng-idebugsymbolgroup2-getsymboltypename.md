# IDebugSymbolGroup2::GetSymbolTypeName

## Description

The **GetSymbolTypeName** methods return the name of the specified symbol's type.

## Parameters

### `Index` [in]

The index of the symbol whose type name you want. The index of a symbol is an identification number. The index ranges from zero through the number of symbols in the symbol group minus one.

### `Buffer` [out, optional]

The name of the symbol's type. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

The size, in characters, of the *Buffer* buffer. This size includes the space for the '\0' terminating character.

### `NameSize` [out, optional]

The size, in characters, of the name of the symbol's type. This size includes the space for the '\0' terminating character. If *NameSize* is **NULL**, this information is not returned.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The size of the buffer was smaller than the size of the name of the symbol's type. The buffer is filled with the truncated name. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

For more information about symbol groups, see [Scopes and Symbol Groups](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups).

## See also

[GetNumberSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-getnumbersymbols)

[IDebugSymbolGroup2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbolgroup2)

[IDebugSymbols::GetTypeName](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-gettypename)