# INetworkConnectionCostEvents::ConnectionCostChanged

## Description

The **ConnectionCostChanged** method notifies an application of a network cost change for a connection.

## Parameters

### `connectionId` [in]

A unique ID that identifies the connection on which the cost change event occurred.

### `newCost` [in]

A DWORD value that represents the new cost of the connection. The lowest 16 bits represent the cost level, and the highest 16 bits represent the flags. Possible values are defined by the [NLM_CONNECTION_COST](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ne-netlistmgr-nlm_connection_cost) enumeration.

## Return value

This method returns S_OK on success.

## See also

[INetworkConnectionCostEvents](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworkconnectioncostevents)