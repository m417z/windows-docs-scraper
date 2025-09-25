# IDebugHostSymbols::FindModuleByLocation

## Description

The FindModuleByLocation method will look through the given host context and determine what module contains the address given by the specified location. It will then return an interface to such module.

## Parameters

### `context`

This host context will be searched for a loaded module containing the address given by the *moduleLocation* argument.

### `moduleLocation`

The module in the given context which contains the address specified by this argument will be returned (or the method will fail).

### `module`

If the module is found, an interface to the module will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHost> spHost; /* get the host */

ComPtr<IDebugHostSymbols> spSym;
if (SUCCEEDED(spHost.As(&spSym)))
{
    // Find the module which contains the address 0x7f638000 in the current
    // UI context (process) of the debug host
    ComPtr<IDebugHostModule> spModule;
    if (SUCCEEDED(sySym->FindModuleByLocation(USE_CURRENT_HOST_CONTEXT,
                                              0x7f638000,
                                              &spModule)))
    {
        // spModule is the module which contains the VA 0x7f638000
    }
}
```

## See also

[IDebugHostSymbols interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostsymbols)