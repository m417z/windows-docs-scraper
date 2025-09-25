# INetworkListManager::get_IsConnected

## Description

The **get_IsConnected** property specifies if the local machine has network connectivity.

## Parameters

### `pbIsConnected` [out]

If **TRUE** , the network has at least local connectivity via ipv4 or ipv6 or both. The network may also have internet connectivity. Thus, the network is connected.

If **FALSE**, the network does not have local or internet connectivity. The network is not connected.

## Return value

Returns S_OK if successful.

## See also

[INetworkListManager](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworklistmanager)