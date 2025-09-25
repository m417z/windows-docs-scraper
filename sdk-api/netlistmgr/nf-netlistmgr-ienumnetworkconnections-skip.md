# IEnumNetworkConnections::Skip

## Description

The **Skip** method skips over the next specified number of elements in the enumeration sequence.

## Parameters

### `celt` [in]

Number of elements to skip over in the enumeration.

## Return value

Returns S_OK if the method succeeds. Otherwise, the method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The number of elements skipped was not *celt*. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[IEnumNetworkConnections](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-ienumnetworkconnections)