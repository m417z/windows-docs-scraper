# CreateClusterNameAccount function

## Description

Creates a [cluster name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-name) resource and then uses it add a cluster to a domain, even if the machines that host the cluster aren't members of the domain.The **PCLUSAPI_CREATE_CLUSTER_NAME_ACCOUNT** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

A handle to the cluster to add the cluster name resource to.

### `pConfig` [in]

A pointer to the [CREATE_CLUSTER_NAME_ACCOUNT](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-create_cluster_name_account) structure that contains the information about the [cluster name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-name) resource to create, and the domain credentials to use.

### `pfnProgressCallback` [in, optional]

A pointer to the [ClusterSetupProgressCallback](https://learn.microsoft.com/windows/desktop/api/clusapi/nc-clusapi-pcluster_setup_progress_callback) callback function that receives the status of updates to the cluster.

### `pvCallbackArg` [in, optional]

Callback function arguments for the *pfnProgressCallback* parameter.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**. If the operation fails, the function returns a system error code.

## See also

[Failover Cluster Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-management-functions)