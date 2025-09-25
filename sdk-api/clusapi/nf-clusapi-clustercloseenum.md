# ClusterCloseEnum function

## Description

Closes a cluster enumeration handle originally opened by [ClusterOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusteropenenum).

## Parameters

### `hEnum` [in]

Cluster enumeration handle to close. This is a handle originally returned by the [ClusterOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusteropenenum) function.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[ClusterEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterenum)

[ClusterOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusteropenenum)