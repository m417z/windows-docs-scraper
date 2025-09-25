# IAppxManifestPackageId::GetPublisher

## Description

Gets the name of the package publisher as defined in the manifest.

## Parameters

### `publisher` [out, retval]

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The publisher of the package.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**.

## Remarks

Publisher name information is specified using the **Publisher** attribute of the [Identity](https://learn.microsoft.com/uwp/schemas/appxpackage/appxmanifestschema/element-identity) element in the package manifest.

The caller must free the memory allocated for *publisher* using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## See also

[IAppxManifestPackageId](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestpackageid)