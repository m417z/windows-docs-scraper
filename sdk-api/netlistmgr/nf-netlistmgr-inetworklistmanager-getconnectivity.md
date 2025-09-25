# INetworkListManager::GetConnectivity

## Description

The **GetConnectivity** method returns the overall connectivity state of the machine.

## Parameters

### `pConnectivity` [out]

Pointer to an [NLM_CONNECTIVITY](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ne-netlistmgr-nlm_connectivity) enumeration value that contains a bitmask that specifies the network connectivity of this machine.

## Return value

Returns S_OK if the method succeeds.

## See also

[INetworkListManager](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworklistmanager)