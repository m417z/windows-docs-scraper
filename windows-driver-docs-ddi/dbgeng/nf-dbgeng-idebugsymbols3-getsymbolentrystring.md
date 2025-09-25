# IDebugSymbols3::GetSymbolEntryString

## Description

The **GetSymbolEntryString** method returns string information for the specified symbol.

## Parameters

### `Id` [in]

Specifies the symbols whose memory regions are being requested. The [DEBUG_MODULE_AND_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_module_and_id) structure contains the module containing the symbol and the symbol ID of the symbol within the module.

### `Which` [in]

Specifies the index of the desired string. Often this is zero, as most symbols contain just one string (their name). But some symbols may contain more than one string -- for example, annotation symbols.

### `Buffer` [out, optional]

Receives the name of the symbol. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

Specifies the size in characters of the buffer *Buffer*. This size includes the space for the '\0' terminating character.

### `StringSize` [out, optional]

Receives the size in characters of the symbol's name. This size includes the space for the '\0' terminating character. If *StringSize* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information about symbols, see [Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4).

## See also

[GetSymbolEntriesByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getsymbolentriesbyname)

[GetSymbolEntriesByOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getsymbolentriesbyoffset)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)