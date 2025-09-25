# IEnumConnectionPoints::Next

## Description

Retrieves the specified number of items in the enumeration sequence.

## Parameters

### `cConnections` [in]

The number of items to be retrieved. If there are fewer than the requested number of items left in the sequence, this method retrieves the remaining elements.

### `ppCP` [out]

An array of enumerated items.

The enumerator is responsible for calling [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref), and the caller is responsible for calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) through each pointer enumerated. If *cConnections* is greater than 1, the caller must also pass a non-NULL pointer passed to *lpcFetched* to know how many pointers to release.

### `pcFetched` [out]

The number of items that were retrieved. This parameter is always less than or equal to the number of items requested.

## Return value

If the method retrieves the number of items requested, the return value is S_OK. Otherwise, it is S_FALSE.

## See also

[IConnectionPoint](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iconnectionpoint)

[IEnumConnectionPoints](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ienumconnectionpoints)