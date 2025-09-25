# ISettingsItem::RemoveListElement

## Description

Removes an existing list element of the supplied name.There cannot be multiples with same name because the name must be unique. If an item of the specified name is not present, the method returns **WCM_E_STATENOTNOTFOUND**.

## Parameters

### `ElementName` [in]

The name of the element to be removed.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |
| **WCM_E_STATENODENOTFOUND** | Indicates an attempt to remove an item that does not exist. |
| **E_INVALIDARG** | Indicates that the item that is not of setting type list. |
| **WCM_E_READONLYITEM** | Indicates that the item cannot be written, either because it is a read-only item, or because the namespace was opened in ReadOnly mode. |
| **WCM_E_WRONGESCAPESTRING** | Indicates that the path contains an unrecognized XML escape sequence. |
| **WCM_E_INVALIDPATH** | Indicates that the path is incorrectly formatted. |
| **WCM_E_INVALIDKEY** | Indicates that the path is incorrectly specified and references the wrong key for the list item. |

## See also

[ISettingsItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsitem)