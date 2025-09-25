# ClusterCloseEnumEx function

## Description

Closes a handle to an enumeration that was opened by the [ClusterOpenEnumEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusteropenenumex) function.

## Parameters

### `hClusterEnum` [in]

The handle to the cluster enumeration to close. This is a handle that originally was returned by [ClusterOpenEnumEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusteropenenumex).

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[Failover Cluster Management Function](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-management-functions)