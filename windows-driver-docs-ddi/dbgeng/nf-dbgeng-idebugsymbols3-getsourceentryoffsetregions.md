# IDebugSymbols3::GetSourceEntryOffsetRegions

## Description

 Returns all memory regions known to be associated
with a source entry.

## Parameters

### `Entry` [in]

An entry as a [DEBUG_SYMBOL_SOURCE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_symbol_source_entry) structure.

### `Flags` [in]

A bit-set that contains options that affect the behavior of this method.

### `Regions` [out]

The memory regions associated with the source entry.

### `RegionsCount` [in]

The number of regions associated with the entry.

### `RegionsAvail` [out, optional]

A pointer to the number of regions available to the entry.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

This function returns all known memory regions that associated
with a specified source entry. Simple symbols have a single region that starts from their base. More complicated regions, such as functions that have multiple code areas, can have an arbitrarily
large number of regions.

## See also

[DEBUG_SYMBOL_SOURCE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_symbol_source_entry)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)

[IDebugSymbols3::GetSymbolEntryOffsetRegions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getsymbolentryoffsetregions)