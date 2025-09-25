# ICreateTypeLib::SetVersion

## Description

Sets the major and minor version numbers of the type library.

## Parameters

### `wMajorVerNum` [in]

The major version number for the library.

### `wMinorVerNum` [in]

The minor version number for the library.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **TYPE_E_INVALIDSTATE** | The state of the type library is not valid for this operation. |

## See also

[ICreateTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypelib)