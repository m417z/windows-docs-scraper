# IDebugSymbols3::GetSymbolEntryBySymbolEntry

## Description

Allows navigation within the
symbol entry hierarchy.

## Parameters

### `FromId` [in]

A pointer to a [DEBUG_MODULE_AND_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_module_and_id) structure as the input ID.

### `Flags` [in]

A bit-set that contains options that affect the behavior of this method.

### `ToId` [out]

A pointer to a [DEBUG_MODULE_AND_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_module_and_id) structure as the output ID.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DEBUG_MODULE_AND_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_module_and_id)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)