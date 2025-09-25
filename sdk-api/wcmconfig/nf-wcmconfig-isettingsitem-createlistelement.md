# ISettingsItem::CreateListElement

## Description

Creates a new list element.

## Parameters

### `KeyData` [in]

The information for the key that defines the identity of the new list item. To determine the correct value for the key data parameter, consult the information returned from [ISettingsItem::GetListKeyInformation](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsitem-getlistkeyinformation). The variant obtained from **ISettingsItem::GetListKeyInformation** should be coercible to the type of the key. If the **ISettingsItem::GetListKeyInformation** method returns **S_FALSE**, use a string type for the key data.

### `Child` [out]

A pointer to the newly created [ISettingsItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsitem) list item.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |
| **HRESULT_FROM_WIN32 (ERROR_INVALID_OPERATION)** | Indicates that the method is called on an item that is not of setting type list. |
| **WCM_E_INVALIDVALUE, WCM_E_INVALIDVALUEFORMAT, or WCM_E_INVALIDDATATYPE** | Indicates an attempt to create a list where the key cannot be coerced to the correct type. |
| **WCM_E_READONLYITEM** | Indicates that the item cannot be written, either because it is a read-only item, or because the namespace was opened in ReadOnly mode. |

## Remarks

**Note** When creating a scalar list item, you must set a value on the resulting [ISettingsItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsitem) before releasing it, or it will not be persisted.

## See also

[ISettingsItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsitem)