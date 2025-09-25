# ITfCategoryMgr::FindClosestCategory

## Description

Finds the category closest to the specified GUID from a list of categories.

## Parameters

### `rguid` [in]

Specifies the address of the GUID for which to find the closest category.

### `pcatid` [out]

Pointer to the **GUID** that receives the CATID for the closest category.

### `ppcatidList` [in]

Pointer to a pointer that specifies an array of CATIDs to search for the closest category.

### `ulCount` [in]

Specifies the number of elements in the array of the *ppcatidList* parameter.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method obtained the closest category from the list of categories, or the method was unable to obtain a category from the list and indicates this with a *pcatid* parameter pointer to GUID_NULL. |
| **S_FALSE** | The method was unable to find a category for the specified GUID and signals this with a *pcatid* parameter pointer to GUID_NULL. |
| **E_FAIL** | The method cannot access the internal table. |
| **E_INVALIDARG** | The specified *pcatid* parameter was **NULL** on input, or the list of categories contained a **NULL** element when the *ulCount* parameter was nonzero. |
| **E_OUTOFMEMORY** | There is insufficient memory to perform the operation. |

## Remarks

The closest category to a **GUID** is chosen in one of two modes. In the first mode, the method receives a non-empty category list. It chooses the first matching **CATID** from that list or GUID_NULL if the list does not contain a category that contains the **GUID** . In the second mode, it receives an empty category list. It chooses the first category that contains the **GUID** or GUID_NULL if no category contains the **GUID** .

## See also

[ITfCategoryMgr interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcategorymgr), [ITfCategoryMgr::EnumCategoriesInItem](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-enumcategoriesinitem), [ITfCategoryMgr::EnumItemsInCategory](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-enumitemsincategory), [ITfCategoryMgr::RegisterCategory](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-registercategory)