# IDebugSymbolGroup::GetSymbolName

## Description

The **GetSymbolName** method returns the name of a symbol in a symbol group.

## Parameters

### `Index` [in]

The index of the symbol whose name you want. The index of a symbol is an identification number. The index ranges from zero through the number of symbols in the symbol group minus one.

### `Buffer` [out, optional]

The symbol name. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

The size of the buffer that *Buffer* points to. This size includes the space for the '\0' terminating character.

### `NameSize` [out, optional]

The size of the symbol name. This size includes the space for the '\0' terminating character. If *NameSize* is **NULL**, this information is not returned.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the name of the symbol did not fit in the buffer referred to by the *Buffer* parameter, so a truncated name was returned. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

For more information about symbol groups, see [Scopes and Symbol Groups](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups).

## See also

[GetNumberSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-getnumbersymbols)

[IDebugSymbolGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbolgroup)

[IDebugSymbolGroup2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbolgroup2)