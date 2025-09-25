# IDebugSymbols3::GetSourceEntriesByOffset

## Description

Queries symbol information and returns locations in the target's memory by using an offset.

## Parameters

### `Offset` [in]

The offset of the entry.

### `Flags` [in]

A bit-set that contains options that affect the behavior of this method.

### `Entries` [out]

A pointer to a returned entry as a [DEBUG_SYMBOL_SOURCE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_symbol_source_entry) structure.

### `EntriesCount` [in]

The number of entries.

### `EntriesAvail` [out, optional]

A pointer to the number of entries available.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 This method can return multiple results for a source lookup. This allows for all possible results to be returned.

## See also

[DEBUG_SYMBOL_SOURCE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_symbol_source_entry)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)