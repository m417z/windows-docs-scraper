# CreateClusterCNOless function

## Description

Creates a cluster without [cluster name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-name) and [IP Address](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-address) resources. The allows you to create clusters that are domain joined but not managed by Active Directory, and clusters that are not members of a domain. **PCLUSAPI_CREATE_CLUSTER_CNOLESS** defines a pointer to this function.

## Parameters

### `pConfig` [in]

A pointer to the [CREATE_CLUSTER_CONFIG](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-create_cluster_config) structure that contains the cluster configuration.

### `pfnProgressCallback` [in, optional]

A pointer to the [ClusterSetupProgressCallback](https://learn.microsoft.com/windows/desktop/api/clusapi/nc-clusapi-pcluster_setup_progress_callback) callback function that receives the status of updates to the cluster.

### `pvCallbackArg` [in, optional]

Callback function arguments for the *pfnProgressCallback* parameter.

## Return value

A handle to the new cluster or **NULL**. A non **NULL**
value does not indicate success (even if all nodes are added to the cluster, the [IP Address](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-address) or
[Network Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-name) resource creation can fail). After a failure, you should check the parameters
passed through the *pfnProgressCallback* parameter.

| Return code | Description |
| --- | --- |
| ****NULL**** | Less than a majority of nodes were successfully created. For more information about the error, call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |

## Remarks

To create clusters that are not domain joined, a non-domain account must have permission to manage the cluster remotely.

## See also

[Failover Cluster Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-management-functions)