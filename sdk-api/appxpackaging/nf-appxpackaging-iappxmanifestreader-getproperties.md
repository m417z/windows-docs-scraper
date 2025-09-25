# IAppxManifestReader::GetProperties

## Description

Gets the properties of the package as defined in the manifest.

## Parameters

### `packageProperties` [out, retval]

Type: **[IAppxManifestProperties](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestproperties)****

Properties of the package as described by the manifest.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**.

## Remarks

Properties are specified using the [Properties](https://learn.microsoft.com/uwp/schemas/appxpackage/appxmanifestschema/element-properties) element in the manifest.

#### Examples

For an example, see [Quickstart: Read app package manifest info](https://learn.microsoft.com/windows/desktop/appxpkg/how-to-query-package-identity-information).

## See also

[IAppxManifestReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestreader)