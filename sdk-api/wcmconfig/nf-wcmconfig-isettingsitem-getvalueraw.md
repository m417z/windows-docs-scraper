# ISettingsItem::GetValueRaw

## Description

Gets the value from the current item as
a byte array.

**Note** The caller must release the
returned byte array by calling CoTaskMemFree.

## Parameters

### `Data` [out]

An array of BYTE pointers, allocated with [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc), of length DataSize.

### `DataSize` [out]

The length of the data.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |
| **HRESULT_FROM_WIN32 (ERROR_INVALID_OPERATION)** | Indicates that the item is not a scalar setting. |
| **E_OUTOFMEMORY** | Indicates that there are insufficient resources to allocate the return data. |
| **S_FALSE** | Indicates that there is no value for the item. |

## See also

[ISettingsItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsitem)