# ISettingsNamespace::GetSettingByPath

## Description

Gets the setting object specified by a path.

## Parameters

### `Path` [in]

The path of the object.

### `Setting` [out]

A pointer to an [ISettingsItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsitem) object that represents the retrieved object.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |
| **WCM_E_STATENODENOTFOUND** | Indicates an attempt to get an item that does not exist. |
| **WCM_E_INVALIDPATH** | Indicates that the path is not formatted correctly. |
| **WCM_E_INVALIDKEY** | Indicates that the path contains an unrecognized XML escape sequence. |
| **WCM_E_WRONGESCAPESTRING** | Indicates that the path is incorrectly specified and references the wrong key for a list item. |

## See also

[ISettingsNamespace](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsnamespace)