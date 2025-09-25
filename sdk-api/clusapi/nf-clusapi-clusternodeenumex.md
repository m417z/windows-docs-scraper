# ClusterNodeEnumEx function

## Description

Retrieves the specified cluster node from a [CLUSTER_ENUM_ITEM](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-cluster_enum_item) enumeration.

## Parameters

### `hNodeEnum` [in]

A handle to the [CLUSTER_ENUM_ITEM](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-cluster_enum_item) enumeration that contains the cluster node to retrieve.

### `dwIndex` [in]

The index that identifies the next object to enumerate. This parameter should be zero for the first call to the [ClusterEnumEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterenumex) function and then be incremented for subsequent calls.

### `pItem` [in, out]

A pointer that receives the returned cluster node.

### `cbItem` [in, out]

On input, the size of the *pItem* parameter.

On output, either the required size in bytes of the buffer if the buffer is too small, or the number of bytes written into the buffer.

## Return value

| Return code | Description |
| --- | --- |
| **ERROR_NO_MORE_ITEMS** | *dwIndex* is larger than the number of items in the enumeration. |
| **ERROR_MORE_DATA** | The buffer is too small. |
| **ERROR_SUCCESS** | The buffer was filled successfully. |

## See also

[CLUSTER_ENUM_ITEM](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-cluster_enum_item)

[Node Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/node-management-functions)