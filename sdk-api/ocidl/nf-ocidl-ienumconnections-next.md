## Description

Retrieves the specified number of items in the enumeration sequence. An item corresponds to a [CONNECTDATA](https://learn.microsoft.com/windows/win32/api/ocidl/ns-ocidl-connectdata) structure.

## Parameters

### `cConnections` [in]

The number of items to be retrieved. If there are fewer than the requested number of items left in the sequence, this method retrieves the remaining elements.

### `rgcd` [out]

An array of enumerated items.

The enumerator is responsible for allocating any memory, and the caller is responsible for freeing it. If *celt* is greater than 1, the caller must also pass a non-NULL pointer passed to *pceltFetched* to know how many pointers to release.

### `pcFetched` [out]

The number of items that were retrieved. This parameter is always less than or equal to the number of items requested.

## Return value

If the method retrieves the number of items requested, the return value is S_OK. Otherwise, it is S_FALSE.

## Remarks

After this method returns successfully, the caller is responsible for calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) (see the **pUnk** member of [CONNECTDATA](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-connectdata)) for each element in the array. If *cConnections* is greater than one, the caller must also pass a non-NULL pointer to *lpcFetched* to get the number of pointers it has to be released.

E_NOTIMPL is not allowed as a return value. If an error value is returned, no entries in the array are valid on exit, and therefore no release is required.

## See also

[CONNECTDATA](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-connectdata)

[IEnumConnections](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ienumconnections)