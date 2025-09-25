# ClusterEnumEx function

## Description

Enumerates the objects in a cluster, and then gets the name and properties of the cluster object.

## Parameters

### `hClusterEnum` [in]

A handle to the enumerator that is returned by the [ClusterOpenEnumEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusteropenenumex) function.

### `dwIndex` [in]

The index that identifies the next cluster object to enumerate. This parameter should be zero for the first call to the **ClusterEnumEx** function and then be incremented for subsequent calls.

### `pItem` [in, out]

A pointer that receives the returned cluster object properties.

### `cbItem` [in, out]

On input, the size of the *pItem* parameter.

On output, either the required size in bytes of the buffer if the buffer is too small, or the number of bytes that are written into the buffer.

## Return value

| Return code | Description |
| --- | --- |
| **ERROR_NO_MORE_ITEMS** | The *dwIndex* parameter is larger than the number of items in the enumeration. |
| **ERROR_MORE_DATA** | The buffer is too small. |
| **ERROR_SUCCESS** | The buffer was filled successfully. |

## See also

[CLUSTER_ENUM_ITEM](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-cluster_enum_item)

[Failover Cluster Management Function](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-management-functions)