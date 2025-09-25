# ClusterGroupEnumEx function

## Description

Retrieves an item in the enumeration.The **PCLUSAPI_CLUSTER_GROUP_ENUM_EX** type defines a pointer to this function.

## Parameters

### `hGroupEnumEx` [in]

The handle to the enumeration from which the item will be retrieved.

### `dwIndex` [in]

The zero-based index of the item in the enumeration.

### `pItem` [in, out]

A pointer to the buffer to be filled.

### `cbItem` [in, out]

On input, the size of *pItem*.

On output, either the required size in bytes of the buffer if the buffer is too small, or the number of bytes written into the buffer.

## Return value

| Return code | Description |
| --- | --- |
| **ERROR_NO_MORE_ITEMS** | *dwIndex* is larger than the number of items in the enumeration. |
| **ERROR_MORE_DATA** | The buffer is too small. |
| **ERROR_SUCCESS** | The buffer was filled successfully. |

## Remarks

The **ClusterGroupEnumEx** function doesn't connect to the cluster, because the *hGroupEnumEx* already contains the enumeration data. The data is copied into the buffer but no data is retrieved from the cluster.