# ClusterUpgradeFunctionalLevel function

## Description

Initiates a rolling upgrade of the operating system on a cluster. **PCLUSAPI_CLUSTER_UPGRADE** defines a pointer to this function.

## Parameters

### `hCluster` [in]

A handle to the cluster to upgrade.

### `perform` [in]

**True** to initiate the rolling upgrade; otherwise **false**.

### `pfnProgressCallback` [in, optional]

A pointer to the [ClusterUpgradeProgressCallback](https://learn.microsoft.com/windows/desktop/api/clusapi/nc-clusapi-pcluster_upgrade_progress_callback) callback function that retrieves the status of the rolling upgrade.

### `pvCallbackArg` [in, optional]

A pointer to the arguments for **pfnProgressCallback**.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**. If the operation fails, the function returns a system error code.

## See also

[ClusterFunctionalLevel](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusters-clusterfunctionallevel)

[Failover Cluster Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-management-functions)