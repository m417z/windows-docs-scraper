# IEnumNetworkConnections::Clone

## Description

The **Clone** method creates an enumerator that contains the same enumeration state as the enumerator currently in use.

## Parameters

### `ppEnumNetwork` [out]

Pointer to new [IEnumNetworkConnections](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-ienumnetworkconnections) interface instance.

## Return value

Returns S_OK if the method succeeds. Otherwise, the method returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *ppEnum* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_UNEXPECTED** | Failed for unknown reasons. |

## See also

[IEnumNetworkConnections](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-ienumnetworkconnections)