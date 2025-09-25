# INetworkConnectionEvents::NetworkConnectionPropertyChanged

## Description

The **NetworkConnectionPropertyChanged** method notifies a client when property change events related to a specific network connection occur.

## Parameters

### `connectionId` [in]

A GUID that identifies the network connection on which the event occurred.

### `flags` [in]

The [NLM_CONNECTION_PROPERTY_CHANGE](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ne-netlistmgr-nlm_connection_property_change) flags for this connection.

## Return value

Returns S_OK if the method succeeds.

## See also

[INetworkConnectionEvents](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworkconnectionevents)

[NLM_CONNECTION_PROPERTY_CHANGE](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ne-netlistmgr-nlm_connection_property_change)