# INetworkEvents::NetworkConnectivityChanged

## Description

The **NetworkConnectivityChanged** method is called when network connectivity related changes occur.

## Parameters

### `networkId` [in]

 A **GUID** that specifies the new network that was added.

### `newConnectivity` [in]

[NLM_CONNECTIVITY](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ne-netlistmgr-nlm_connectivity) enumeration value that contains the new connectivity of this network.

## Return value

Returns S_OK if the method succeeds.

## See also

[INetworkEvents](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworkevents)

[NLM_CONNECTIVITY](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ne-netlistmgr-nlm_connectivity)