# ISettingsItem::CreateSettingByPath

## Description

Creates a setting object specified by the path.

## Parameters

### `Path` [in]

A pointer to the path.

### `Setting` [out]

A pointer to the newly created [ISettingsItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsitem) item.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |
| **WCM_E_STATENODENOTFOUND** | Indicates that the method is called to create an item that is not a list element or does not already exist. |
| **WCM_E_READONLYITEM** | Indicates that the item cannot be written, such as if it is a read only item, or the namespace was opened in ReadOnly mode. |
| **WCM_E_INVALIDVALUE, WCM_E_INVALIDVALUEFORMAT, or WCM_E_INVALIDDATATYPE** | Indicates that the value provided for the key cannot be coerced to the appropriate type, such as a string value coerced to an unsigned integer. |
| **WCM_E_WRONGESCAPESTRING** | Indicates that the path contains an unrecognized XML escape sequence. |
| **WCM_E_INVALIDKEY** | Indicates that the path is incorrectly specified and references the wrong key for a list item. |

## Remarks

**Note** When creating a scalar list item, you must set a value on the resulting [ISettingsItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsitem) before releasing it, or it will not be persisted.

## See also

[ISettingsItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsitem)