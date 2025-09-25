# IOfflineFilesSetting::DeletePreference

## Description

Removes a preference setting.

## Parameters

### `dwScope` [in]

Indicates which preference setting is to be deleted. Must be one of the following.

#### OFFLINEFILES_SETTING_SCOPE_USER (0x00000001)

The user preference setting is to be deleted.

#### OFFLINEFILES_SETTING_SCOPE_COMPUTER (0x00000002)

The machine preference setting is to be deleted.

## Return value

**S_OK** if the preference is removed successfully or an error value otherwise.

Returns `HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)` if the requested preference setting is not currently configured.

Returns `HRESULT_FROM_WIN32(ERROR_ACCESS_DENIED)` if the caller is trying to remove a per-machine preference and is not a local administrator.

## Remarks

This method requires system administrator privilege if the preference is a per-machine preference.

## See also

[IOfflineFilesSetting](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessetting)