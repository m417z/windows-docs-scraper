# ITargetInfo::SetTemporaryStoreLocation

## Description

Sets the current temporary store location.

## Parameters

### `TemporaryStoreLocation` [in]

The current temporary store location.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |
| **HRESULT_FROM_WIN32 (ERROR_INVALID_OPERATION)** | Indicates that the target processor architecture has already been set. |
| **E_OUTOFMEMORY** | Indicates that system resources are low. |

## See also

[ITargetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-itargetinfo)