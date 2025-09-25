# INetworkEvents::NetworkPropertyChanged

## Description

The **NetworkPropertyChanged** method is called when a network property change is detected.

## Parameters

### `networkId` [in]

GUID that specifies the network on which this event occurred.

### `flags` [in]

[NLM_NETWORK_PROPERTY_CHANGE](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ne-netlistmgr-nlm_network_property_change) enumeration value that specifies the network property that changed.

## Return value

Returns S_OK if the method succeeds.

## See also

[INetworkEvents](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworkevents)

[NLM_NETWORK_PROPERTY_CHANGE](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ne-netlistmgr-nlm_network_property_change)