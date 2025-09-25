# ClusterNetworkEnum function

## Description

Enumerates [cluster objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects) on a
[network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks), returning the name of one object with each call. The **PCLUSAPI_CLUSTER_NETWORK_ENUM** type defines a pointer to this function.

## Parameters

### `hNetworkEnum` [in]

A handle to an existing enumeration object originally returned by the
[ClusterNetworkOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternetworkopenenum) function.

### `dwIndex` [in]

The index used to identify the next entry to be enumerated. This parameter should be zero for the first call
to **ClusterNetworkEnum** and then incremented for
subsequent calls.

### `lpdwType` [out]

A pointer to the type of object returned. The following value of the
[CLUSTER_NETWORK_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_network_enum) enumeration is returned with
each call.

#### CLUSTER_NETWORK_ENUM_NETINTERFACES (1)

The object is a [network interface](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interfaces).

### `lpszName` [out]

A pointer to a null-terminated Unicode string containing the name of the returned object.

### `lpcchName` [in, out]

A pointer to the size of the *lpszName* buffer as a count of characters. On input,
specify the maximum number of characters the buffer can hold, including the terminating
**NULL**. On output, specifies the number of characters in the resulting name, excluding
the terminating **NULL**.

## Return value

The function returns one of the following values.

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The operation completed successfully. |
| **ERROR_MORE_DATA**<br><br>234 (0xEA) | More data is available. This value is returned if the buffer pointed to by *lpszName* is not big enough to hold the result. The *lpcchName* parameter returns the number of characters in the result, excluding the terminating **NULL**. |
| **ERROR_NO_MORE_ITEMS**<br><br>259 (0x103) | No more data is available. This value is returned if there are no more objects of the requested type to be returned. |

## Remarks

The **ClusterNetworkEnum** function is typically
used to iterate through a collection of objects of one or more types belonging to a network object. If, for
example, an application wants to enumerate all of the
[network interface](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interfaces) objects on a network, it
calls [ClusterNetworkOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternetworkopenenum) to
open a network enumerator that can process network interface objects. The *dwType*
parameter is set to **CLUSTER_NETWORK_ENUM_NETINTERFACES** to specify network interfaces
as the object type to be enumerated. With the handle that
[ClusterNetworkOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternetworkopenenum) returns,
the application calls **ClusterNetworkEnum**
repeatedly to retrieve each of the objects. The *lpdwType* parameter points to the type
of object that is retrieved.

Note that *lpcchName* refers to a count of characters and not a count of bytes, and
that the returned size does not include the terminating **NULL** in the count. For more
information on sizing buffers, see
[Data Size Conventions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-size-conventions).

#### Examples

See [Enumerating Objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/enumerating-objects).

## See also

[CLUSTER_NETWORK_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_network_enum)

[Cluster Network Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-management-functions)

[ClusterNetworkCloseEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternetworkcloseenum)

[ClusterNetworkOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternetworkopenenum)