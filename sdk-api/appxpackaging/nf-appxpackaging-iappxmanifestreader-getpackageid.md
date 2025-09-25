# IAppxManifestReader::GetPackageId

## Description

Gets the package identifier defined in the manifest.

## Parameters

### `packageId` [out, retval]

Type: **[IAppxManifestPackageId](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestpackageid)****

The package identifier.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method when you have finished using the *packageId* object.

#### Examples

For an example, see [Quickstart: Read app package manifest info](https://learn.microsoft.com/windows/desktop/appxpkg/how-to-query-package-identity-information).

## See also

[IAppxManifestReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestreader)