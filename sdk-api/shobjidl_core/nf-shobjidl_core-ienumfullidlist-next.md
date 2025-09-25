# IEnumFullIDList::Next

## Description

Retrieves a specified number of IDLIST_ABSOLUTE items.

## Parameters

### `celt` [in]

Type: **ULONG**

The number of items referenced in the array referenced by the *rgelt* parameter.

### `rgelt` [out]

Type: **PIDLIST_ABSOLUTE***

On success, contains a PIDL array. The implementation must allocate these item identifiers using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc). The calling application is responsible for freeing the item identifiers using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `pceltFetched` [out]

Type: **ULONG***

On success, contains a pointer to a value that receives a count of the absolute item identifiers actually returned in *rgelt*. The count can be smaller than the value specified in the *celt* parameter. This parameter can be **NULL** on entry only if *celt* is 1, because in that case the method can only retrieve one (S_OK) or zero (S_FALSE) items.

## Return value

Type: **HRESULT**

Returns S_OK if the method successfully retrieved the requested *celt* elements. This method only returns S_OK if the full count of requested items are successfully retrieved.

S_FALSE indicates that more items were requested than remained in the enumeration. The value pointed to by the *pceltFetched* parameter specifies the actual number of items retrieved. Note that the value will be 0 if there are no more items to retrieve.

Returns a COM-defined error value otherwise.