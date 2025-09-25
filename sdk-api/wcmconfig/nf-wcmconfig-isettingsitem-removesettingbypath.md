# ISettingsItem::RemoveSettingByPath

## Description

Removes a setting object specified by its path. Unlike GetSettingByPath, the use of **ISettingsItem::RemoveSettingByPath** is not advocated for attributes.

## Parameters

### `Path` [in]

The path of the item to remove. The path is relative to the current item.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |
| **WCM_E_STATENODENOTFOUND** | Indicates an attempt to remove an item that does not exist. |
| **HRESULT_FROM_WIN32 (ERROR_INVALID_OPERATION)** | Indicates an attempt to remove an element that is not a list element. |
| **WCM_E_READONLYITEM** | Indicates that the item cannot be written, either because it is a read-only item, or because the namespace was opened in ReadOnly mode. |
| **WCM_E_WRONGESCAPESTRING** | Indicates that the path contains an unrecognized XML escape sequence. |
| **WCM_E_INVALIDPATH** | Indicates that the path is incorrectly formatted. |
| **WCM_E_INVALIDKEY** | Indicates that the path is incorrectly specified and references the wrong key for the list item. |

## See also

[ISettingsItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsitem)