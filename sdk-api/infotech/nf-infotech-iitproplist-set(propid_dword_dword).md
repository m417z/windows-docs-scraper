# IITPropList::Set(PROPID,DWORD,DWORD)

## Description

Sets a property to a given value or deletes a property from the list.

## Parameters

### `PropID` [in]

ID of property to set.

### `dwData` [in]

Value of property.

### `dwOperation` [in]

The operation you want to perform. Can be any of the following flags:

| Value | Meaning |
| --- | --- |
| **PROP_ADD** | Add property to list |
| **PROP_DELETE** | Remove property from list |
| **PROP_UPDATE** | Update property in list |

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The property list was successfully set. |
| **E_DUPLICATE** | The property already exists in the list (applies to adding). |
| **E_OUTOFMEMORY** | Memory could not be allocated when adding a property. |
| **E_NOTEXIST** | The property does not exist (applies to deleting and updating). |
| **E_NOTIMPL** | The specified operation is not available. |

## Remarks

Use this method to set properties with numerical values.

## See also

[IITPropList](https://learn.microsoft.com/previous-versions/windows/desktop/api/infotech/nn-infotech-iitproplist)