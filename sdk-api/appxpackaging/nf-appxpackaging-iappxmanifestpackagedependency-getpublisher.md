# IAppxManifestPackageDependency::GetPublisher

## Description

Gets the name of the publisher that produced the package on which the current package depends.

## Parameters

### `publisher` [out]

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The name of the publisher.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the publisher is not defined for the dependency, this method returns **S_OK**, and *publisher* is **NULL**.

The caller must free the memory allocated for *publisher* using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## See also

[IAppxManifestPackageDependency](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestpackagedependency)