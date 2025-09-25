# ITfCategoryMgr::RegisterCategory

## Description

Adds a specified GUID to the specified category in the Windows registry.

## Parameters

### `rclsid` [in]

Contains the CLSID of the text service that owns the item.

### `rcatid` [in]

Contains a GUID value that identifies the category to register the item under. This can be a user-defined category or one of the [predefined category values](https://learn.microsoft.com/windows/desktop/TSF/predefined-category-values).

### `rguid` [in]

Contains a GUID value that identifies the item to register.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITfCategoryMgr interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcategorymgr), [ITfCategoryMgr::UnregisterCategory](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-unregistercategory), [Predefined Category Values](https://learn.microsoft.com/windows/desktop/TSF/predefined-category-values)