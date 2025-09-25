# INetworkListManagerEvents::ConnectivityChanged

## Description

The **NetworkConnectivityChanged** method is called when network connectivity related changes occur.

## Parameters

### `newConnectivity` [in]

An [NLM_CONNECTIVITY](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ne-netlistmgr-nlm_connectivity) enumeration value that contains the new connectivity settings of the machine.

## Return value

Returns S_OK if the method succeeds.

## See also

[INetworkListManagerEvents](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworklistmanagerevents)

[NLM_CONNECTIVITY](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ne-netlistmgr-nlm_connectivity)