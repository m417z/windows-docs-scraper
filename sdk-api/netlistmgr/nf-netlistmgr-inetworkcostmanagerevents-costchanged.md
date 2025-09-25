# INetworkCostManagerEvents::CostChanged

## Description

The **CostChanged** method is called to indicates a cost change for either machine-wide Internet connectivity, or the first-hop of routing to a specific destination on a connection.

## Parameters

### `newCost` [in]

A DWORD that represents the new cost of the connection. The lowest 16 bits represent the cost level, and the highest 16 bits represent the flags. Possible values are defined by the [NLM_CONNECTION_COST](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ne-netlistmgr-nlm_connection_cost) enumeration.

### `pDestAddr` [in]

An [NLM_SOCKADDR](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ns-netlistmgr-nlm_sockaddr) structure containing an IPv4/IPv6 address that identifies the destination on which the event occurred. If *destAddr* is NULL, the change is a machine-wide Internet connectivity change.

## Return value

Returns S_OK on success.

## See also

[INetworkCostManagerEvents](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworkcostmanagerevents)