# INetworkCostManagerEvents::DataPlanStatusChanged

## Description

The **DataPlanStatusChanged** method is called to indicate a change to the status of a data plan associated with either a connection used for machine-wide Internet connectivity, or the first-hop of routing to a specific destination on a connection.

## Parameters

### `pDestAddr`

An [NLM_SOCKADDR](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ns-netlistmgr-nlm_sockaddr) structure containing an IPv4/IPv6 address that identifies the destination for which the event occurred. If *destAddr* is NULL, the change is a machine-wide Internet connectivity change.

## Return value

Returns S_OK on success.

## See also

[INetworkCostManagerEvents](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworkcostmanagerevents)