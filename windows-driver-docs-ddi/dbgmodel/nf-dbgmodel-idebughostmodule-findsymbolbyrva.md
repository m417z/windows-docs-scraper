# IDebugHostModule::FindSymbolByRVA

## Description

The FindSymbolByRVA method will find a single matching symbol at the given relative virtual address within the module. If there is not a single symbol at the supplied RVA (e.g.: there are multiple matches), an error will be returned by this method. Note that this method will prefer returning a private symbol over a symbol in the publics table.

## Parameters

### `rva`

The relative virtual address (offset) within the module for which to locate a matching symbol in the symbolic information for the module.

### `symbol`

The found symbol will be returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostModule> spModule;

// Find the symbol which is at 0x100000 within the module
ComPtr<IDebugHostSymbol> spSymbol;
if (SUCCEEDED(spModule->FindSymbolByRVA(0x100000, &spSymbol)))
{
    // spSymbol contains the symbol which is at RVA 0x100000 within the
    // module.  Note that it may be any kind of symbol
}
```

## See also

[IDebugHostModule interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostmodule)