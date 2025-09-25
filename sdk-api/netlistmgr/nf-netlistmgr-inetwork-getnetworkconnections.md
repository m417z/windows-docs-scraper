# INetwork::GetNetworkConnections

## Description

The **GetNetworkConnections** method returns an enumeration of all network connections for a network. A network can have multiple connections to it from different interfaces or different links from the same interface.

## Parameters

### `ppEnumNetworkConnection` [out]

Pointer to an [IEnumNetworkConnections](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-ienumnetworkconnections) interface instance that enumerates the list of local connections to this network.

## Return value

Returns S_OK if the method succeeds.

## See also

[INetwork](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetwork)