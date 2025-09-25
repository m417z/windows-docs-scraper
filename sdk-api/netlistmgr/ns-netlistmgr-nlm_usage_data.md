# NLM_USAGE_DATA structure

## Description

The **NLM_USAGE_DATA** structure stores information that indicates the data usage of a plan.

## Members

### `UsageInMegabytes`

The data usage of a plan, represented in megabytes.

### `LastSyncTime`

The timestamp of last time synced with carriers about the data usage stored in this structure.

## Remarks

If usage is not supplied, **UsageInMegabytes** is set to **NLM_UNKNOWN_DATAPLAN_STATUS** (0xFFFFFFFF), and **LastSyncTime** is set to 0.

## See also

[INetworkCostManager::GetDataPlanStatus](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nf-netlistmgr-inetworkcostmanager-getdataplanstatus)

[NLM_DATAPLAN_STATUS](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ns-netlistmgr-nlm_dataplan_status)