# ClusterGroupEnum function

## Description

Enumerates the [resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) in a
[group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) or the [nodes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) that
are the preferred owners of a group, returning the name of the resource or node with each call. The **PCLUSAPI_CLUSTER_GROUP_ENUM** type defines a pointer to this function.

## Parameters

### `hGroupEnum` [in]

A group enumeration handle returned by the
[ClusterGroupOpenEnum](https://learn.microsoft.com/windows/win32/api/clusapi/nf-clusapi-clustergroupopenenum) function.

### `dwIndex` [in]

The index of the resource or node to return. This parameter should be zero for the first call to
**ClusterGroupEnum** and then incremented for
subsequent calls.

### `lpdwType` [out]

A pointer to the type of object returned by
**ClusterGroupEnum**. The following are valid values
of the [CLUSTER_GROUP_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_group_enum) enumeration.

#### CLUSTER_GROUP_ENUM_CONTAINS (1)

The object is one of the resources in the group.

#### CLUSTER_GROUP_ENUM_NODES (2)

The object is one of the nodes in the preferred owners list of the group.

### `lpszResourceName` [out]

A pointer to a null-terminated Unicode string containing the name of the returned resource or node.

### `lpcchName` [in, out]

A pointer to the size of the *lpszResourceName* buffer as a count of characters. On
input, specify the maximum number of characters the buffer can hold, including the terminating
**NULL**. On output, specifies the number of characters in the resulting name, excluding
the terminating **NULL**.

## Return value

The function can returns one of the following values.

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The operation completed successfully. |
| **ERROR_MORE_DATA**<br><br>234 (0xEA) | More data is available. This value is returned if the buffer pointed to by *lpszResourceName* is not big enough to hold the result. The *lpcchName* parameter returns the number of characters in the result, excluding the terminating **NULL**. |
| **ERROR_NO_MORE_ITEMS**<br><br>259 (0x103) | No more data is available. This value is returned if there are no more resources or nodes to be returned. |

If the operation was not successful due to a problem other than those described with the
**ERROR_NO_MORE_ITEMS** or **ERROR_MORE_DATA** values,
**ClusterGroupEnum** returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

Note that *lpcchName* refers to a count of characters and not a count of bytes, and
that the returned size does not include the terminating **NULL** in the count. For more
information on sizing buffers, see
[Data Size Conventions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-size-conventions).

Do not call **ClusterGroupEnum** from any resource DLL
entry point function. **ClusterGroupEnum** can safely be
called from a worker thread. For more information, see
[Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

#### Examples

See [Enumerating Objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/enumerating-objects).

## See also

[ClusterGroupCloseEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clustergroupcloseenum)

[ClusterGroupOpenEnum](https://learn.microsoft.com/windows/win32/api/clusapi/nf-clusapi-clustergroupopenenum)

[Group Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/group-management-functions)