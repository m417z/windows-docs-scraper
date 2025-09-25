# IAppxManifestPackageDependency::GetName

## Description

Gets the name of the package on which the current package has a dependency.

## Parameters

### `name` [out]

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The name of the package.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**.

## Remarks

The caller must free the memory allocated for *name* using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## See also

[IAppxManifestPackageDependency](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestpackagedependency)