# IAppxManifestReader::GetResources

## Description

Gets an enumerator that iterates through the resources defined in the manifest.

## Parameters

### `resources` [out, retval]

Type: **[IAppxManifestResourcesEnumerator](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestresourcesenumerator)****

The enumerator that iterates through the resources.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**.

## Remarks

Resources are specified using the [Resources](https://learn.microsoft.com/uwp/schemas/appxpackage/appxmanifestschema/element-resources) element in the manifest.

Call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method when you have finished using the *resources* object.

## See also

[IAppxManifestReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestreader)