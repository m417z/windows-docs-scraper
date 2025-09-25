# IDebugSymbols3::GetSourceEntryBySourceEntry

## Description

Allows navigation within the
source entries.

## Parameters

### `FromEntry` [in]

A pointer to a [DEBUG_SYMBOL_SOURCE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_symbol_source_entry) as the input entry.

### `Flags` [in]

A bit-set that contains options that affect the behavior of this method.

### `ToEntry` [out]

A pointer to a [DEBUG_SYMBOL_SOURCE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_symbol_source_entry) as the output entry.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DEBUG_SYMBOL_SOURCE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_symbol_source_entry)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)