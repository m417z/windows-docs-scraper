# IEnumNetworkConnections::Next

## Description

The **Next** method gets the next specified number of elements in the enumeration sequence.

## Parameters

### `celt` [in]

Number of elements requested.

### `rgelt` [out]

Pointer to a list of pointers returned by [INetworkConnection](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworkconnection).

### `pceltFetched` [out]

Pointer to the number of elements supplied. May be **NULL** if *celt* is one.

## Return value

Returns S_OK if the method succeeds. Otherwise, the method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The number of elements skipped was not *celt*. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppElements* parameter is not a valid pointer. |

## See also

[IEnumNetworkConnections](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-ienumnetworkconnections)