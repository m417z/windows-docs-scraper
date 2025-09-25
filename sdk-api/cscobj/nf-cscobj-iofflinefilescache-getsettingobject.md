# IOfflineFilesCache::GetSettingObject

## Description

Creates an object that represents a particular Offline Files setting.

## Parameters

### `pszSettingName` [in]

Case-insensitive name of the setting. One of the following values:

### `ppSetting` [out]

If the setting exists, a pointer to the object's [IOfflineFilesSetting](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessetting) interface is returned.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

Returns `HRESULT_FROM_WIN32(ERROR_INVALID_NAME)` if the setting name is invalid.

## Remarks

This method is available to both administrators and non-administrators. Security restrictions are enforced on a setting-by-setting basis. For example, only administrators can alter a setting that applies to all users on the computer.

## See also

[IOfflineFilesCache](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilescache)