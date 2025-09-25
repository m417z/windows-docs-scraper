# ITfCategoryMgr::EnumCategoriesInItem

## Description

Obtains an IEnumGUID interface that enumerates all categories to which the specified GUID belongs.

## Parameters

### `rguid` [in]

Contains a GUID value that identifies the item to enumerate the categories for.

### `ppEnum` [out]

Pointer to an IEnumGUID interface pointer that receives the enumerator.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | *ppEnum* is invalid. |
| **E_OUTOFMEMORY** | There is insufficient memory to perform the operation. |

## See also

[ITfCategoryMgr interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcategorymgr), [ITfCategoryMgr::EnumItemsInCategory](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-enumitemsincategory), [ITfCategoryMgr::RegisterCategory](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-registercategory)