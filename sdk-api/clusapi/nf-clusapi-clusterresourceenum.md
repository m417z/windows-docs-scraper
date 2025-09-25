# ClusterResourceEnum function

## Description

Enumerates a [resource's](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) dependent resources,
[nodes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes), or both. It returns the name of one
[cluster object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects) with each call. The **PCLUSAPI_CLUSTER_RESOURCE_ENUM** type defines a pointer to this function.

## Parameters

### `hResEnum` [in]

A resource enumeration handle returned from
the [ClusterResourceOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceopenenum) function.

### `dwIndex` [in]

The index of the resource or node object to return. This parameter should be zero for the first call to the
**ClusterResourceEnum** function and then
incremented for subsequent calls.

### `lpdwType` [out]

The type of object returned by
**ClusterResourceEnum**.

The possible values are one of the following [CLUSTER_RESOURCE_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_enum) enumeration values:

#### CLUSTER_RESOURCE_ENUM_DEPENDS (1)

The object is a resource and *hResEnum* is a resource that depends on this object.

#### CLUSTER_RESOURCE_ENUM_PROVIDES (2)

The object is a resource that depends on the resource identified by *hResEnum*.

#### CLUSTER_RESOURCE_ENUM_NODES (4)

The object is a node that can host the resource identified by *hResEnum*.

### `lpszName` [out]

A pointer to a null-terminated Unicode string containing the name of the returned object.

### `lpcchName` [in, out]

A pointer to the size of the *lpszName* buffer as a count of characters. On input,
specify the maximum number of characters the buffer can hold, including the terminating null character. On
output, specifies the number of characters in the resulting name, excluding the terminating null character.

## Return value

The function returns one of the following values.

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The operation completed successfully or the *lpszName* parameter is **NULL**. |
| **ERROR_MORE_DATA**<br><br>234 (0xEA) | The buffer pointed to by the *lpszName* parameter is not big enough to hold the result. The *lpcchName* parameter returns the number of characters in the result, excluding the terminating null character. |
| **ERROR_NO_MORE_ITEMS**<br><br>259 (0x103) | There are no more objects to be returned. |
| **[System error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes)** | Any other returned error code indicates that the operation failed. |

## Remarks

Note that *lpcchName* refers to a count of characters and not a count of bytes, and
that the returned size does not include the terminating null character in the count. For more information on
sizing buffers, see [Data Size Conventions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-size-conventions).

Do not call **ClusterResourceEnum** from any
resource DLL entry point function.
**ClusterResourceEnum** can safely be called from a
worker thread. For more information, see
[Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

#### Examples

See [Enumerating Objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/enumerating-objects).

## See also

[Cluster Resource Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-management-functions)

[ClusterResourceCloseEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecloseenum)

[ClusterResourceOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceopenenum)