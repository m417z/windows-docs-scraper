# IAppxManifestPackageId::GetPackageFamilyName

## Description

Gets the package family name.

## Parameters

### `packageFamilyName` [out, retval]

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The package family name.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**.

## Remarks

The package family name is a case-insensitive string, which can be used to uniquely identify a family of packages with the same name and publisher.

This string is a serialized form of the package ID, and it is suitable for naming objects such as files and directories. Because the package family name does not contain information about package version, architecture, or resources, it is useful when you need a version-independent reference to a package.

The caller must free the memory for *packageFamilyName* using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## See also

[IAppxManifestPackageId](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestpackageid)