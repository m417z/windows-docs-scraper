# ClusterResourceTypeEnum function

## Description

Enumerates a [resource type's](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types) possible owner
[nodes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) or resources, returning the name of one node or
resource per call. The **PCLUSAPI_CLUSTER_RESOURCE_TYPE_ENUM** type defines a pointer to this function.

## Parameters

### `hResTypeEnum` [in]

Resource type enumeration handle returned from
[ClusterResourceTypeOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourcetypeopenenum).

### `dwIndex` [in]

Index of the [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) or node object to return. This
parameter should be zero for the first call to
**ClusterResourceTypeEnum** and then
incremented for subsequent calls.

### `lpdwType` [out]

Type of object returned by
**ClusterResourceTypeEnum**. The following
values of the [CLUSTER_RESOURCE_TYPE_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_type_enum)
enumeration are valid.

#### CLUSTER_RESOURCE_TYPE_ENUM_NODES (1)

The object is a node that can be a possible owner of the resource type.

#### CLUSTER_RESOURCE_TYPE_ENUM_RESOURCES (2)

The object is a resource that is an instance of the resource type.

### `lpszName` [out]

Pointer to a null-terminated Unicode string containing the name of the returned object.

### `lpcchName` [in, out]

Pointer to the size of the *lpszName* buffer as a count of characters. On input,
specify the maximum number of characters the buffer can hold, including the terminating
**NULL**. On output, specifies the number of characters in the resulting name, excluding
the terminating **NULL**.

## Return value

The function returns one of the following values.

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The operation was successful. |
| **ERROR_NO_MORE_ITEMS**<br><br>259 | There are no more objects to be returned. |
| **ERROR_MORE_DATA**<br><br>234 | The buffer pointed to by *lpszName* is not big enough to hold the result. The *lpcchName* parameter returns the number of characters in the result, excluding the terminating **NULL**. |
| **[System error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes)** | The operation failed. |

## Remarks

Note that *lpcchName* refers to a count of characters and not a count of bytes, and
that the returned size does not include the terminating **NULL** in the count. For more information on sizing
buffers, see [Data Size Conventions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-size-conventions).

#### Examples

See [Enumerating Objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/enumerating-objects).

## See also

[CLUSTER_RESOURCE_TYPE_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_type_enum)

[ClusterResourceTypeCloseEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourcetypecloseenum)

[ClusterResourceTypeOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourcetypeopenenum)

[Resource Type Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-type-management-functions)