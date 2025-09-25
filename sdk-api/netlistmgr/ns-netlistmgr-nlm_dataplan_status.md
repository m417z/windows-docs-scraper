# NLM_DATAPLAN_STATUS structure

## Description

The **NLM_DATAPLAN_STATUS** structure stores the current data plan status information supplied by the carrier.

## Members

### `InterfaceGuid`

The unique ID of the interface associated with the data plan. This GUID is determined by the system when a data plan is first used by a system connection.

### `UsageData`

An [NLM_USAGE_DATA](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ns-netlistmgr-nlm_usage_data) structure containing current data usage value expressed in megabytes, as well as the system time at the moment this value was last synced.

If this value is not supplied, [NLM_USAGE_DATA](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ns-netlistmgr-nlm_usage_data) will indicate **NLM_UNKNOWN_DATAPLAN_STATUS** for **UsageInMegabytes** and a value of '0' will be set for **LastSyncTime.**

### `DataLimitInMegabytes`

The data plan usage limit expressed in megabytes. If this value is not supplied, a default value of **NLM_UNKNOWN_DATAPLAN_STATUS** is set.

### `InboundBandwidthInKbps`

The maximum inbound connection bandwidth expressed in kbps. If this value is not supplied, a default value of **NLM_UNKNOWN_DATAPLAN_STATUS** is set.

### `OutboundBandwidthInKbps`

The maximum outbound connection bandwidth expressed in kbps. If this value is not supplied, a default value of **NLM_UNKNOWN_DATAPLAN_STATUS** is set.

### `NextBillingCycle`

The start time of the next billing cycle. If this value is not supplied, a default value of '0' is set.

### `MaxTransferSizeInMegabytes`

The maximum suggested transfer size for this network expressed in megabytes. If this value is not supplied, a default value of **NLM_UNKNOWN_DATAPLAN_STATUS** is set.

### `Reserved`

Reserved for future use.

## See also

[INetworkConnectionCost::GetDataPlanStatus](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nf-netlistmgr-inetworkconnectioncost-getdataplanstatus)

[INetworkCostManagerEvents::DataPlanStatusChanged](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nf-netlistmgr-inetworkcostmanagerevents-dataplanstatuschanged)

[NLM_USAGE_DATA](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ns-netlistmgr-nlm_usage_data)