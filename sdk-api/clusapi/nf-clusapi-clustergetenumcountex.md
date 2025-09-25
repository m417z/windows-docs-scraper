# ClusterGetEnumCountEx function

## Description

Returns the
number of cluster objects that are associated with a
cluster enumeration handle.

## Parameters

### `hClusterEnum` [in]

The handle to a cluster enumeration. This handle is obtained from the
[ClusterOpenEnumEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusteropenenumex) function. A valid handle is required. This
parameter cannot be NULL.

## Return value

The number of
objects that are associated with the enumeration handle.

## See also

[Failover Cluster Management Function](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-management-functions)