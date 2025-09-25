# ITfCategoryMgr::UnregisterCategory

## Description

Removes a specified GUID from the specified category in the Windows registry.

## Parameters

### `rclsid` [in]

Contains the CLSID of the text service that owns the item.

### `rcatid` [in]

Contains a GUID that identifies the category that the item is registered under.

### `rguid` [in]

Contains a GUID that identifies the item to remove.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITfCategoryMgr interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcategorymgr), [ITfCategoryMgr::RegisterCategory](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-registercategory)