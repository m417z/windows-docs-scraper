# NLM_CONNECTION_COST enumeration

## Description

The **NLM_CONNECTION_COST** enumeration specifies a set of cost levels and cost flags supported in Windows 8 Cost APIs.

## Constants

### `NLM_CONNECTION_COST_UNKNOWN:0`

The cost is unknown.

### `NLM_CONNECTION_COST_UNRESTRICTED:0x1`

The connection is unlimited and is considered to be unrestricted of usage charges and capacity constraints.

### `NLM_CONNECTION_COST_FIXED:0x2`

The use of this connection is unrestricted up to a specific data transfer limit.

### `NLM_CONNECTION_COST_VARIABLE:0x4`

This connection is regulated on a per byte basis.

### `NLM_CONNECTION_COST_OVERDATALIMIT:0x10000`

The connection is currently in an OverDataLimit state as it has exceeded the carrier specified data transfer limit.

### `NLM_CONNECTION_COST_CONGESTED:0x20000`

The network is experiencing high traffic load and is congested.

### `NLM_CONNECTION_COST_ROAMING:0x40000`

The connection is roaming outside the network and affiliates of the home provider.

### `NLM_CONNECTION_COST_APPROACHINGDATALIMIT:0x80000`

The connection is approaching the data limit specified by the carrier.

## Remarks

The value returned by the [INetworkConnectionCost::GetCost](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nf-netlistmgr-inetworkconnectioncost-getcost) method can have multiple bits set with the values specified by this enumeration.

## See also

[INetworkConnectionCost::GetCost](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nf-netlistmgr-inetworkconnectioncost-getcost)