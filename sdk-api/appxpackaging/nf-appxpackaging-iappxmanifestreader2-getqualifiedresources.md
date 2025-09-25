# IAppxManifestReader2::GetQualifiedResources

## Description

Gets an enumerator that iterates through the qualified resources that are defined in the manifest.

## Parameters

### `resources` [out, retval]

Type: **[IAppxManifestQualifiedResourcesEnumerator](https://learn.microsoft.com/previous-versions/dn280306(v=vs.85))****

The enumerator that iterates through the qualified resources.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**.

## Remarks

Resources are specified using the [Resources](https://learn.microsoft.com/uwp/schemas/appxpackage/appxmanifestschema/element-resources) element in the manifest.

Call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method when you have finished using the *resources* object.

## See also

[IAppxManifestReader2](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestreader2)