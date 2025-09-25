# IAppxManifestPackageDependency::GetMinVersion

## Description

Gets the minimum version of the package on which the current package has a dependency.

## Parameters

### `minVersion` [out]

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The minimum version of the package.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the minimum version is not defined for the dependency, this method returns **S_OK** and *minVersion* is 0.

The version is specified using the **MinVersion** attribute of the [PackageDependency](https://learn.microsoft.com/uwp/schemas/appxpackage/appxmanifestschema/element-packagedependency) element in the package manifest. The specification in the manifest is in quad notation:

*major*.*minor*.*build*.*revision*

This method converts this notation to a **UINT64** value as follows:

* The high-order word contains the major version
* The next word contains the minor version
* The next word contains the build number
* The low-order word contains the revision

## See also

[IAppxManifestPackageDependency](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestpackagedependency)