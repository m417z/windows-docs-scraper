# ITargetInfo::GetProperty

## Description

Gets a property value for the offline installation location.

## Parameters

### `Offline` [in]

**True** if the installation location is offline.

### `Property` [in]

The name of the property.

### `Value` [out]

The value of the property.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |
| **S_FALSE** | Indicates that the requested property does not exist. |
| **E_OUTOFMEMORY** | Indicates that there are insufficient resources to return information to the user. |

## See also

[ITargetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-itargetinfo)