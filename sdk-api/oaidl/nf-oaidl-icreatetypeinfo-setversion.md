# ICreateTypeInfo::SetVersion

## Description

Sets the major and minor version number of the type information.

## Parameters

### `wMajorVerNum` [in]

The major version number.

### `wMinorVerNum` [in]

The minor version number.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_ACCESSDENIED** | Cannot write to the destination. |
| **TYPE_E_INVALIDSTATE** | The state of the type library is not valid for this operation. |

## See also

[ICreateTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo)