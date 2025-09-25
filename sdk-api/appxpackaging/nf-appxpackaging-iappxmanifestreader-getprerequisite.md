# IAppxManifestReader::GetPrerequisite

## Description

Gets the specified prerequisite as defined in the package manifest.

## Parameters

### `name` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the prerequisite, either "OSMinVersion" or "OSMaxVersionTested".

### `value` [out, retval]

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The specified prerequisite. In the manifest the dot-trio representation is Major.Minor.AppPlatform. This is converted to the 64-bit value as the follows:
The highest order word contains the Major version. The next word contains the Minor version. The next word contains the optional AppPlatform version, if specified.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The prerequisite defined in *name* is not defined in the manifest. |

## Remarks

Prerequisites are specified using the [OSMinVersion](https://learn.microsoft.com/uwp/schemas/appxpackage/appxmanifestschema/element-osminversion) and [OSMaxVersionTested](https://learn.microsoft.com/uwp/schemas/appxpackage/appxmanifestschema/element-osmaxversiontested) elements in the package manifest.

## See also

[IAppxManifestReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestreader)