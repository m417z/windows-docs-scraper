# IAppxManifestPackageId::GetVersion

## Description

Gets the version of the package as defined in the manifest.

## Parameters

### `packageVersion` [out, retval]

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The version of the package.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**.

## Remarks

The version is specified using the **Version** attribute of the [Identity](https://learn.microsoft.com/uwp/schemas/appxpackage/appxmanifestschema/element-identity) element in the package manifest. The specification in the manifest is in quad notation:

*major*.*minor*.*build*.*revision*

This method converts this notation to a **UINT64** value as follows:

* The high-order word contains the major version
* The next word contains the minor version
* The next word contains the build number
* The low-order word contains the revision

#### Examples

For an example, see [Quickstart: Read app package manifest info](https://learn.microsoft.com/windows/desktop/appxpkg/how-to-query-package-identity-information).

## See also

[IAppxManifestPackageId](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestpackageid)