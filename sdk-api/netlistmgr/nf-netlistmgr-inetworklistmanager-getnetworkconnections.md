# INetworkListManager::GetNetworkConnections

## Description

The **GetNetworkConnections** method enumerates a complete list of the network connections that have been made.

## Parameters

### `ppEnum` [out]

Pointer to a pointer that receives an [IEnumNetworkConnections](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-ienumnetworkconnections) interface instance that enumerates all network connections on the machine.

## Return value

Returns S_OK if the method succeeds. Otherwise, the method returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The pointer passed is **NULL**. |

## See also

[INetworkListManager](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworklistmanager)