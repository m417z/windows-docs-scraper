# IDebugSymbols3::GetSymbolEntriesByName

## Description

The **GetSymbolEntriesByName** method returns the [symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4) whose names match a given pattern.

## Parameters

### `Symbol` [in]

Specifies the pattern used to determine which symbols to return. This method returns the symbols whose name matches the [string wildcard syntax](https://learn.microsoft.com/windows-hardware/drivers/debugger/string-wildcard-syntax) pattern *Symbol*.

### `Flags` [in]

Set to zero.

### `Ids` [out, optional]

Receives the symbols. This is an array of *IdsCount* entries of type [DEBUG_MODULE_AND_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_module_and_id). If *Ids* is **NULL**, this information is not returned.

### `IdsCount` [in]

Specifies the number of entries that the array *Ids* can hold.

### `Entries` [out, optional]

Receives the number of symbols whose names match the pattern *Symbol*. If *entries* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information about symbols, see [Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4).

## See also

[GetSymbolEntriesByOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getsymbolentriesbyoffset)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)