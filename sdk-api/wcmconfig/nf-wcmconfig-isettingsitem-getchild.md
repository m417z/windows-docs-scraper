# ISettingsItem::GetChild

## Description

Gets the child item that has the specified name.

## Parameters

### `Name` [in]

The name of the child item.

### `Child` [out]

A pointer to an [ISettingsItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsitem) object that corresponds to the child item.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |
| **WCM_E_STATENODENOTFOUND** | Indicates that the requested name is not a child of the item. |
| **WCM_E_WRONGESCAPESTRING** | Indicates that the name contains an unrecognized XML escape sequence. |
| **WCM_E_INVALIDPATH** | Indicates that the name is not formatted correctly. |
| **WCM_E_INVALIDKEY** | Indicates that the path is incorrectly specified and references the wrong key for the list item. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_OPERATION)** | Indicates that the item does not support children. |

## See also

[ISettingsItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsitem)