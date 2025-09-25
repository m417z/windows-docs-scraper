# ISettingsItem::SetValue

## Description

Sets the value of an item.

## Parameters

### `Value` [in]

Variant that contains the value of the item.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |
| **WCM_E_INVALIDVALUE, WCM_E_INVALIDVALUEFORMAT, or WCM_E_INVALIDDATATYPE** | Indicates that the value is not of the correct type for the item, or that the value cannot be coerced to the correct type. |
| **WCM_E_READONLYITEM** | Indicates that the item cannot be written, either because it is a read-only item, or because the namespace was opened in ReadOnly mode. |

## See also

[ISettingsItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsitem)