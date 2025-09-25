# IDebugSymbols3::GetSourceEntryStringWide

## Description

Queries symbol information and returns locations in the target's memory.

## Parameters

### `Entry` [in]

An entry as a [DEBUG_SYMBOL_SOURCE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_symbol_source_entry) structure.

### `Which` [in]

A value that determines which types to return.

### `Buffer` [out]

 A pointer to a Unicode character string buffer for the results.

### `BufferSize` [in]

The size of the buffer.

### `StringSize` [out, optional]

Pointer to the size of the string.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

This method can return multiple results for a source lookup. This allows for all possible results to be returned.

## See also

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)