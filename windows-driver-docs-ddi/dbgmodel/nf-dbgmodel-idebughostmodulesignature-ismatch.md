# IDebugHostModuleSignature::IsMatch

## Description

The IsMatch method compares a particular module (as given by an [IDebugHostModule](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostmodule) symbol) against a signature, comparing the module name and version to the name and version range indicated in the signature. An indication of whether the given module symbol matches the signature is returned.

## Parameters

### `pModule`

The module symbol to compare against the module signature.

### `isMatch`

An indication of whether the given module symbol matches the module signature is returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostSymbols> spSym;   /* get the host's symbols interface */
ComPtr<IDebugHostModule> spModule; /* find a module */

ComPtr<IDebugHostModuleSignature> spModuleSignature;
if (SUCCEEDED(spSym->CreateModuleSignature(
    L"Windows.UI.Xaml.dll",
    L"6.3",
    nullptr,
    &spModuleSignature)))
{
    bool isMatch;
    if (SUCCEEDED(spModuleSignature->IsMatch(spModule.Get(), &isMatch)))
    {
        // isMatch indicates whether the module is a match for the signature.
        // In this case, that means the module is named Windows.UI.Xaml.dll
        // and the version is at least 6.3(.0.0).
    }
}
```

## See also

[IDebugHostModuleSignature interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostmodulesignature)