# ClusterEnum function

## Description

Enumerates the [cluster objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects) in a
[cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly), returning the name of one object with each
call. The **PCLUSAPI_CLUSTER_ENUM** type defines a pointer to this function.

## Parameters

### `hEnum` [in]

A cluster enumeration handle returned by the
[ClusterOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusteropenenum) function.

### `dwIndex` [in]

The index used to identify the next entry to be enumerated. This parameter should be zero for the first call
to **ClusterEnum** and then incremented for subsequent
calls.

### `lpdwType` [out]

A pointer to the type of object returned. One of the following values of the
[CLUSTER_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_enum) enumeration is returned with each call.

#### CLUSTER_ENUM_NODE (1 (0x1))

Enumerates the [nodes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) in the cluster.

#### CLUSTER_ENUM_RESTYPE (2 (0x2))

Enumerates the [resource types](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types) in the cluster.

#### CLUSTER_ENUM_RESOURCE (4 (0x4))

Enumerates the [resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) in the cluster.

#### CLUSTER_ENUM_GROUP (8 (0x8))

Enumerates the [groups](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) in the cluster.

#### CLUSTER_ENUM_NETWORK (16 (0x10))

Enumerates the [networks](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks) in the cluster.

#### CLUSTER_ENUM_NETINTERFACE (32 (0x20))

Enumerates the [network interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interfaces) in the
cluster.

#### CLUSTER_ENUM_SHARED_VOLUME_RESOURCE (1073741824 (0x40000000))

Enumerates the cluster shared volumes used by the cluster.

**Note** Unlike most other enumeration bitmasks, this value must be used alone. Do not use the
**OR** operator to combine it with other bitmasks.

**Windows Server 2008:** The **CLUSTER_ENUM_SHARED_VOLUME_RESOURCE** value is not supported before
Windows Server 2008 R2.

#### CLUSTER_ENUM_INTERNAL_NETWORK (2147483648 (0x80000000))

Enumerates the networks used by the cluster for internal communication. The networks are enumerated in
order of highest-to-lowest priority as established by
the [SetClusterNetworkPriorityOrder](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-setclusternetworkpriorityorder)
function.

**Note** Unlike most other enumeration bitmasks, this value must be used alone. Do not use the
**OR** operator to combine it with other bitmasks.

#### CLUSTER_ENUM_ALL ((CLUSTER_ENUM_NODE | CLUSTER_ENUM_RESTYPE | CLUSTER_ENUM_RESOURCE | CLUSTER_ENUM_GROUP | CLUSTER_ENUM_NETWORK | CLUSTER_ENUM_NETINTERFACE))

Enumerates all [cluster objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects).

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
| **ERROR_NO_MORE_ITEMS**<br><br>259 (0x103) | No more data is available. This value is returned if there are no more objects of the requested type to be returned. |
| **ERROR_MORE_DATA**<br><br>234 (0xEA) | More data is available. This value is returned if the buffer pointed to by *lpszName* is not big enough to hold the result. The *lpcchName* parameter returns the number of characters in the result, excluding the terminating **NULL**. |

## Remarks

The **ClusterEnum** function is typically used to iterate
through a collection of [cluster objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects) of one
or more types. If, for example, an application wants to enumerate all of the
[nodes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) in a cluster, it calls
[ClusterOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusteropenenum) to open a cluster
enumerator that can process nodes. The *dwType* parameter is set to
**CLUSTER_ENUM_NODE** to specify nodes as the object type to be enumerated. If the
application enumerates [groups](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) in addition to nodes, the
*dwType* parameter is set to
`CLUSTER_ENUM_NODE | CLUSTER_ENUM_GROUP`. With the handle that
**ClusterOpenEnum** returns, the application calls
**ClusterEnum** repeatedly to retrieve each of the objects.
The *lpdwType* parameter points to the type of object that is retrieved.

Note that *lpcchName* refers to a count of characters and not a count of bytes, and
that the returned size does not include the terminating **NULL** in the count. For more
information on sizing buffers, see
[Data Size Conventions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-size-conventions).

#### Examples

See [Enumerating Objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/enumerating-objects).

## See also

[ClusterCloseEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clustercloseenum)

[ClusterOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusteropenenum)

[SetClusterNetworkPriorityOrder](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-setclusternetworkpriorityorder)