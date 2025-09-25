# IEnumIDList::Next

## Description

Retrieves the specified number of item identifiers in the enumeration sequence and advances the current position by the number of items retrieved.

## Parameters

### `celt` [in]

Type: **ULONG**

The number of elements in the array referenced by the *rgelt* parameter.

### `rgelt` [out]

Type: **LPITEMIDLIST***

The address of a pointer to an array of [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) pointers that receive the item identifiers. The implementation must allocate these item identifiers using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc). The calling application is responsible for freeing the item identifiers using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

The [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structures returned in the array are relative to the [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) being enumerated.

### `pceltFetched` [out]

Type: **ULONG***

A pointer to a value that receives a count of the item identifiers actually returned in *rgelt*. The count can be smaller than the value specified in the *celt* parameter. This parameter can be **NULL** on entry only if *celt* = 1, because in that case the method can only retrieve one (S_OK) or zero (S_FALSE) items.

## Return value

Type: **HRESULT**

Returns S_OK if the method successfully retrieved the requested *celt* elements. This method only returns S_OK if the full count of requested items are successfully retrieved.

S_FALSE indicates that more items were requested than remained in the enumeration. The value pointed to by the *pceltFetched* parameter specifies the actual number of items retrieved. Note that the value will be 0 if there are no more items to retrieve.

Returns a COM-defined error value otherwise.

## Remarks

If this method returns a Component Object Model (COM) error code (as determined by the [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macro), then no entries in the *rgelt* array are valid on exit. If this method returns a success code (such as S_OK or S_FALSE), then the **ULONG** pointed to by the *pceltFetched* parameter determines how many entries in the *rgelt* array are valid on exit.

The distinction is important in the case where *celt* > 1. For example, if you pass *celt*=10 and there are only 3 elements left, **pceltFetched* will be 3 and the method will return S_FALSE meaning that you reached the end of the file. The three fetched elements will be stored into *rgelt* and are valid.

## See also

[IEnumIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumidlist)