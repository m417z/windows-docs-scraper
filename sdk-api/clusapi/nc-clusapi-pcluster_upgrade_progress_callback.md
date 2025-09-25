# PCLUSTER_UPGRADE_PROGRESS_CALLBACK callback function

## Description

Retrieves status information for a rolling upgrade of the operating system on a cluster. **PCLUSTER_UPGRADE_PROGRESS_CALLBACK** type defines a pointer to this function.

## Parameters

### `pvCallbackArg`

A pointer to the arguments.

### `eUpgradePhase`

A [CLUSTER_UPGRADE_PHASE](https://learn.microsoft.com/windows/desktop/api/clusapi/ne-clusapi-cluster_upgrade_phase) enumeration values that indicates the state of the rolling upgrade.

## Return value

This function returns one of the following values:

| Return code | Description |
| --- | --- |
| **TRUE** | The operation was successful. |
| **FALSE** | The operation was not successful. |

## See also

[ClusterUpgradeFunctionalLevel](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterupgradefunctionallevel)

[Failover Cluster Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-management-functions)