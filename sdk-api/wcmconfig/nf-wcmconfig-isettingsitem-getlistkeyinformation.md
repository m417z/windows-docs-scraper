# ISettingsItem::GetListKeyInformation

## Description

Gets the list information for this item.

## Parameters

### `KeyName` [out]

The name of the key.

### `DataType` [out]

A [WcmDataType](https://learn.microsoft.com/windows/win32/api/wcmconfig/ne-wcmconfig-wcmdatatype) value that indicates the data type of the item.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |
| **S_FALSE** | Indicates that the list is keyed by keyValue, and KeyName is **NULL**. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_OPERATION)** | Indicates that the item is not a list or list element. |
| **E_OUTOFMEMORY** | Indicates that there are insufficient resources to complete the operation. |

## See also

[ISettingsItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsitem)