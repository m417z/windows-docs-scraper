## Description

The FindSymbolByRVA method will find a single matching symbol at the given relative virtual address within the module. If there is not a single symbol at the supplied RVA (e.g.: there are multiple matches), an error will be returned by this method. Note that this method will prefer returning a private symbol over a symbol in the publics table.

## Parameters

### `rva`

The relative virtual address (offset) within the module for which to locate a matching symbol in the symbolic information for the module.

### `symbol`

The found symbol will be returned here.

### `offset`

The offset value.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDebugHostModule5 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostmodule5)