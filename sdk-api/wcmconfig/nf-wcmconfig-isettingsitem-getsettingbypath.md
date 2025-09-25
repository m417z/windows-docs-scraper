# ISettingsItem::GetSettingByPath

## Description

Gets a setting based on the given path.

## Parameters

### `Path` [in]

Path of the list element or attribute to retrieve. The path is relative to the current setting.

### `Setting` [out]

 An [ISettingsItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsitem) interface pointer used to access the item.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |
| **WCM_E_STATENODENOTFOUND** | Indicates an attempt to get an item that does not exist. |
| **WCM_E_WRONGESCAPESTRING** | Indicates that the path contains an unrecognized XML escape sequence. |
| **WCM_E_INVALIDPATH** | Indicates that the path is incorrectly formatted. |
| **WCM_E_INVALIDKEY** | Indicates that the path is incorrectly specified and references the wrong key for the list item. |

## See also

[ISettingsItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsitem)