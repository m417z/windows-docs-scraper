# IEnumContextProps::Next

## Description

Retrieves the specified number of items in the enumeration sequence.

## Parameters

### `celt` [in]

The number of items to be retrieved. If there are fewer than the requested number of items left in the sequence, this method retrieves the remaining elements.

### `pContextProperties` [out]

An array of enumerated items.

The enumerator is responsible for allocating any memory, and the caller is responsible for freeing it. If *celt* is greater than 1, the caller must also pass a non-NULL pointer passed to *pceltFetched* to know how many pointers to release.

### `pceltFetched` [out]

The number of items that were retrieved. This parameter is always less than or equal to the number of items requested.

## Return value

If the method retrieves the number of items requested, the return value is S_OK. Otherwise, it is S_FALSE.

## See also

[IEnumContextProps](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumcontextprops)