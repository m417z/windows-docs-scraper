# ISettingsNamespace::CreateSettingByPath

## Description

Creates a setting object specified by its path.

## Parameters

### `Path` [in]

The path of the setting object.

### `Setting` [out]

A pointer to an [ISettingsItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsitem) object that represents
the created setting.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |
| **WCM_E_STATENODENOTFOUND** | Indicates an attempt to create a new item that is not a list element. |
| **WCM_E_INVALIDVALUE, WCM_E_INVALIDVALUEFORMAT, or WCM_E_INVALIDDATATYPE** | Indicates an attempt to create a list item where the value provided for the key cannot be coerced to the appropriate type. |
| **WCM_E_READONLYITEM** | Indicates that the item cannot be written, either because it is a read-only item, or because the namespace was opened in ReadOnly mode. |
| **WCM_E_INVALIDPATH** | Indicates that the path is incorrectly formatted. |
| **WCM_E_WRONGESCAPESTRING** | Indicates that the path contains an unrecognized XML escape sequence. |
| **WCM_E_INVALIDKEY** | Indicates that the path is incorrectly specified and references the wrong key for a list item. |

## See also

[ISettingsNamespace](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsnamespace)