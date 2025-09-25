# IOfflineFilesSetting::GetPreference

## Description

Retrieves a per-machine or per-user preference associated with a particular Offline Files setting.

## Parameters

### `pvarValue` [out]

If the preference supports one or more values, the returned [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) object contains those values. If the preference does not support values, the type of the returned **VARIANT** is **VT_EMPTY**.

The method initializes the [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) prior to storing the preference value in it.

### `dwScope` [in]

Indicates which preference is to be retrieved. Must be one of the following.

#### OFFLINEFILES_SETTING_SCOPE_USER (0x00000001)

The per-user preference is to be retrieved.

#### OFFLINEFILES_SETTING_SCOPE_COMPUTER (0x00000002)

The per-machine preference is to be retrieved.

## Return value

**S_OK** if the preference query is successful or an error value otherwise.

Returns `HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)` if the preference is currently not applied.

## See also

[IOfflineFilesSetting](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessetting)