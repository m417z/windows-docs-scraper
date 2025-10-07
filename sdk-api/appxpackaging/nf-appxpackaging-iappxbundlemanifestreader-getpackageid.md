# IAppxBundleManifestReader::GetPackageId

## Description

Retrieves an object that represents the \<Identity> element under the root \<Bundle> element.

## Parameters

### `packageId` [out, retval]

Type: **[IAppxManifestPackageId](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestpackageid)****

The package identifier.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method when you have finished using the *packageId* object.

## See also

[IAppxBundleManifestReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxbundlemanifestreader)