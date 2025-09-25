# IOfflineFilesSetting::SetPreference

## Description

Sets a per-computer or per-user preference associated with an Offline Files setting.

## Parameters

### `pvarValue` [in]

Specifies the value associated with the preference.

If multiple values are associated with the preference, the [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) type includes **VT_ARRAY** and the values are stored in a **SAFEARRAY**.

### `dwScope` [in]

Indicates if the preference to be set is per-user or per-machine. Must be one of the following.

#### OFFLINEFILES_SETTING_SCOPE_USER (0x00000001)

The per-user preference is to be set.

#### OFFLINEFILES_SETTING_SCOPE_COMPUTER (0x00000002)

The per-machine preference is to be set.

## Return value

**S_OK** if the preference is set successfully or an error value otherwise.

Returns `HRESULT_FROM_WIN32(ERROR_INVALID_PARAMETER)` if one or more data values specified via *pvtValue* are not valid.

Returns `HRESULT_FROM_WIN32(ERROR_ACCESS_DENIED)` if the caller is trying to set a per-machine preference and is not a local administrator.

Returns `HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)` if a scope is specified that is not supported by the preference.

## Remarks

This method requires system administrator privileges if the preference is a per-machine preference.

It is important to note that policy cannot be set through the Offline Files API. Policy can be set only through the Group Policy mechanism.

## See also

[IOfflineFilesSetting](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessetting)