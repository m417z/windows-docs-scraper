# GetClusterNetInterface function

## Description

Returns the name of a [node's](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) interface to a [network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks) in a [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly). The **PCLUSAPI_GET_CLUSTER_NET_INTERFACE** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

Handle to a cluster.

### `lpszNodeName` [in]

Pointer to a null-terminated Unicode string containing the name of the node in the cluster.

### `lpszNetworkName` [in]

Pointer to a null-terminated Unicode string containing the name of the network.

### `lpszInterfaceName` [out]

Pointer to an output buffer holding the name of the [network interface](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interfaces).

### `lpcchInterfaceName` [in, out]

Pointer to the size of the *lpszInterfaceName* buffer as a count of characters. On input, specify the maximum number of characters the buffer can hold, including the terminating **NULL**. On output, specifies the number of characters in the resulting name, excluding the terminating **NULL**.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is one of the possible values.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | The buffer pointed to by *lpszInterfaceName* is not big enough to hold the result. The *lpcchInterfaceName* parameter returns the number of characters in the result, excluding the terminating **NULL**. |

## Remarks

Note that *lpcchInterfaceName* refers to a count of characters and not a count of bytes, and that the returned size does not include the terminating **NULL** in the count. For more information on sizing buffers, see [Data Size Conventions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-size-conventions).

## See also

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)