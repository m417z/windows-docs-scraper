## Description

The FindSymbolByName method will find a single global symbol of the given name within the module. If there is not a single symbol matching the given name, an error will be returned by this method. Note that this method will prefer returning a private symbol over a symbol in the publics table.

## Parameters

### `symbolName`

The name of the symbol to locate within the symbolic information for the module.

### `symbol`

The found symbol will be returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostModule5> spModule; /* get a module (see FindModuleByName) */

// Find the symbol for g_someGlobal;
ComPtr<IDebugHostSymbol> spSymbol;
if (SUCCEEDED(spModule->FindSymbolByName(L"g_someGlobal", &spSymbol)))
{
    // spSymbol contains the symbol for g_someGlobal.  It may be any kind of symbol.
}
```

## See also

[IDebugHostModule5 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostmodule5)