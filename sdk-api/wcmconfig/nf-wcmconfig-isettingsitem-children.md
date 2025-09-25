# ISettingsItem::Children

## Description

Gets the dictionary of the child items that correspond to this item.

## Parameters

### `Children` [out]

An [IItemEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-iitemenumerator) interface pointer used to access the children.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |
| **E_OUTOFMEMORY** | Indicates that there are insufficient resources to allocate an enumerator for the children. |
| **HRESULT_FROM_WIN32 (ERROR_INVALID_OPERATION)** | Indicates that the item does not support having children. |

## See also

[ISettingsItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsitem)