# ClusterOpenEnumEx function

## Description

Opens a handle to a cluster in order to iterate through its objects.

## Parameters

### `hCluster` [in]

The handle to the cluster.

### `dwType` [in]

A bitmask that describes the type of objects to be enumerated. This must be one or more of the
[CLUSTER_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_enum) enumeration values.

### `pOptions` [in, optional] [in, optional]

Options.

## Return value

If the operation succeeds, returns a handle to a cluster enumerator.

If the operation fails, the function returns **NULL**. For more information about the
error, call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[CLUSTER_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_enum)

[Failover Cluster Management Function](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-management-functions)