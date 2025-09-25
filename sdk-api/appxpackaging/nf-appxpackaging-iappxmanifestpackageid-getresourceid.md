# IAppxManifestPackageId::GetResourceId

## Description

Gets the package resource identifier as defined in the manifest.

## Parameters

### `resourceId` [out, retval]

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The resource identifier of the package.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**.

## Remarks

The resource identifier is specified using the **ResourceId** attribute of the [Identity](https://learn.microsoft.com/uwp/schemas/appxpackage/appxmanifestschema/element-identity) element in the package manifest.

If no resource identifier is defined in the manifest, this method returns a null string.

The caller must free the memory allocated for *resourceId* using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## See also

[IAppxManifestPackageId](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestpackageid)