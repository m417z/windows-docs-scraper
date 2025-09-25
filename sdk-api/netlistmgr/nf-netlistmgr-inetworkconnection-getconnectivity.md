# INetworkConnection::GetConnectivity

## Description

The **GetConnectivity** method returns the connectivity state of the network connection.

## Parameters

### `pConnectivity` [out]

Pointer to a [NLM_CONNECTIVITY](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ne-netlistmgr-nlm_connectivity) enumeration value that contains a bitmask that specifies the connectivity of this network connection.

## Return value

Returns S_OK if the method succeeds.

## See also

[INetworkConnection](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworkconnection)