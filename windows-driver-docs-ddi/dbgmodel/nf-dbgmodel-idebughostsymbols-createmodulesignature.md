# IDebugHostSymbols::CreateModuleSignature

## Description

The CreateModuleSignature method creates a signature which can be used to match a set of specific modules by name and optionally, by version. There are three components to a module signature:

- A name: a matching module must have a name which is an exact case insensitive match against the name in the signature

- A minimum version: if specified, a matching module must have a minimum version which is at least as high as this version. Versions are specified in "A.B.C.D" format with each subsequent portion being less important than the prior. Only the first segment is mandatory.

- A maximum version: if specified, a matching module must have a maximum version which is no higher than this version. Versions are specified in "A.B.C.D" format with each subsequent portion being less important than the prior. Only the first segment is mandatory.

## Parameters

### `pwszModuleName`

The name that a module must have in order to match the signature (case insensitive).

### `pwszMinVersion`

The minimum version that a module must have in order to match the signature. If this argument is nullptr, there is no minimum version required to match the signature. Versions are specified as strings in "A.B.C.D" format with only the first component being required and subsequent components being less important.

### `pwszMaxVersion`

The maximum version that a module can have in order to match the signature. If this argument is nullptr, there is no upper limit on version number required to match the signature. Versions are specified as strings in "A.B.C.D" format with only the first component being required and subsequent components being less important.

### `ppModuleSignature`

The created module signature object is returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHost> spHost; /* get the host */

ComPtr<IDebugHostSymbols> spSym;
if (SUCCEEDED(spHost.As(&spSym)))
{
    ComPtr<IDebugHostModuleSignature> spBasicSignature;
    if (SUCCEEDED(spSym->CreateModuleSignature(
        L"Windows.UI.Xaml.dll",
        nullptr,
        nullptr,
        &spBasicSignature)))
    {
        // spBasicSignature is a signature which will match any module
        // named "Windows.UI.Xaml.dll" regardless of version.
    }

    ComPtr<IDebugHostModuleSignature> spVersionedSignature;
    if (SUCCEEDED(spSym->CreateModuleSignature(
        L"Windows.UI.Xaml.dll",
        "6.3",
        "10.0.0.0",
        &spVersionedSignature)))
    {
        // spVersionedSignature is a signature which will match a module named
        // "Windows.UI.Xaml.dll" whose version is >= 6.3(.0.0) and whose
        // version <= 10.0.0.0
    }
}
```

## See also

[IDebugHostSymbols interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostsymbols)