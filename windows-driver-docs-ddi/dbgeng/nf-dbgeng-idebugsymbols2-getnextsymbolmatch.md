# IDebugSymbols2::GetNextSymbolMatch

## Description

The **GetNextSymbolMatch** method returns the next symbol found in a symbol search.

## Parameters

### `Handle` [in]

Specifies the handle returned by [StartSymbolMatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-startsymbolmatch) when the search was initialized.

### `Buffer` [out, optional]

Receives the name of the symbol. If *Buffer* is **NULL**, the same symbol will be returned again next time one of these methods are called (with the same handle); this can be used to determine the size of the name of the symbol.

### `BufferSize` [in]

Specifies the size in characters of the buffer. This size includes the space for the '\0' terminating character.

### `MatchSize` [out, optional]

Receives the size in characters of the name of the symbol. This size includes the space for the '\0' terminating character. If *MatchSize* is **NULL**, this information is not returned.

### `Offset` [out, optional]

Receives the location in the target's virtual address space of the symbol. If *Offset* is **NULL**, this information is not returned.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The size of the buffer was too small for the name of the symbol, or *Buffer* was **NULL**. |
| **E_NOINTERFACE** | No more symbols were found matching the pattern. |

## Remarks

The search must first be initialized by [StartSymbolMatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-startsymbolmatch). Once all the desired symbols have been found, [EndSymbolMatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-endsymbolmatch) can be used to release the resources the engine holds for the search.

For more information about symbols, see [Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4).

## See also

[EndSymbolMatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-endsymbolmatch)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)

[StartSymbolMatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-startsymbolmatch)