# ClusterNetworkCloseEnum function

## Description

Closes a [network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks) enumeration handle. The **PCLUSAPI_CLUSTER_NETWORK_CLOSE_ENUM** type defines a pointer to this function.

## Parameters

### `hNetworkEnum` [in]

Handle to the network enumerator to close. This is a handle originally returned by the [ClusterNetworkOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternetworkopenenum) function.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[ClusterNetworkEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternetworkenum)

[ClusterNetworkOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternetworkopenenum)