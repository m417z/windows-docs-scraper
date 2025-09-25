# INetworkConnectionEvents::NetworkConnectionConnectivityChanged

## Description

The **NetworkConnectionConnectivityChanged** method notifies a client when connectivity change events occur on a network connection level.

## Parameters

### `connectionId` [in]

A GUID that identifies the network connection on which the event occurred.

### `newConnectivity` [in]

[NLM_CONNECTIVITY](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ne-netlistmgr-nlm_connectivity) enumeration value that specifies the new connectivity for this network connection.

## Return value

Returns S_OK if the method succeeds.

## See also

[INetworkConnectionEvents](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworkconnectionevents)

[NLM_CONNECTIVITY](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ne-netlistmgr-nlm_connectivity)