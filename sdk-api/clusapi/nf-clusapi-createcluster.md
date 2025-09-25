# CreateCluster function

## Description

Creates and starts a cluster. The cluster consists of the set of nodes specified, with the
[Network Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-name),
[IP Address](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-address), and
[quorum resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/quorum-resource) if specified. The **PCLUSAPI_CREATE_CLUSTER** type defines a pointer to this function.

## Parameters

### `pConfig` [in]

Address of a [CREATE_CLUSTER_CONFIG](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-create_cluster_config)
structure containing configuration information about the cluster to be created.

### `pfnProgressCallback` [in, optional]

Address of callback function that matches the
[PCLUSTER_SETUP_PROGRESS_CALLBACK](https://learn.microsoft.com/windows/desktop/api/clusapi/nc-clusapi-pcluster_setup_progress_callback)
function pointer that will be called periodically to provide progress on the cluster creation.

### `pvCallbackArg` [in, optional]

Argument for the callback function.

## Return value

Handle to the newly created cluster or **NULL**. A non **NULL**
value does not indicate complete success (all nodes will have been added, but not all
[IP Address](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-address) or
[Network Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-name) resources may have been created. The parameters
passed to the function pointed to by the *pfnProgressCallback* parameter should be
checked.

| Return code | Description |
| --- | --- |
| ****NULL**** | Less than a majority of nodes were successfully created. For more information about the error, call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |

## Remarks

The **PCLUSAPI_CREATE_CLUSTER** type defines a pointer to this function and can be
used with the [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) function to call this
function.

After the **CreateCluster** function successfully
completes, at least 30 seconds should be allowed before the
[AddClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-addclusternode) function is called to add additional
nodes.

The **CreateCluster** function successfully completes
after cluster quorum has been achieved. One or more cluster nodes could be in a
**ClusterNodeDown** or **ClusterNodeJoining** state for a few
seconds.

Before calling the **CreateCluster** function,
the [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) function must be called specifying
both **COINIT_MULTITHREADED** and **COINIT_DISABLE_OLE1DDE** for
the *dwCoInit* parameter, as shown in the following code.

``` syntax
CoInitializeEx( NULL, COINIT_MULTITHREADED | COINIT_DISABLE_OLE1DDE );
```

## See also

[AddClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-addclusternode)

[CREATE_CLUSTER_CONFIG](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-create_cluster_config)

[Cluster Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-management-functions)

[DestroyCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-destroycluster)

[PCLUSTER_SETUP_PROGRESS_CALLBACK](https://learn.microsoft.com/windows/desktop/api/clusapi/nc-clusapi-pcluster_setup_progress_callback)