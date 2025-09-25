# ClusterNodeEnum function

## Description

Enumerates the [network interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interfaces) or
[groups](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) installed on a
[node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes), returning the name of each with each call. The **PCLUSAPI_CLUSTER_NODE_ENUM** type defines a pointer to this function.

## Parameters

### `hNodeEnum` [in]

Handle to an existing enumeration object originally returned by the
[ClusterNodeOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternodeopenenum) function.

### `dwIndex` [in]

Index used to identify the next entry to be enumerated. This parameter should be zero for the first call to
**ClusterNodeEnum** and then incremented for subsequent
calls.

### `lpdwType` [out]

Pointer to the type of object returned. The following value of the
[CLUSTER_NODE_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_node_enum) enumeration is returned with each
call.

#### CLUSTER_NODE_ENUM_NETINTERFACES (1)

The object is a network interface.

#### CLUSTER_NODE_ENUM_GROUPS (0x00000002)

The object is a cluster group.

**Windows Server 2008:** The **CLUSTER_NODE_ENUM_GROUPS** value is not supported before
Windows Server 2008 R2.

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
| **ERROR_SUCCESS**<br><br>0 | The operation completed successfully. |
| **ERROR_NO_MORE_ITEMS**<br><br>259 (0x103) | No more data is available. This value is returned if there are no more objects of the requested type to be returned. |
| **ERROR_MORE_DATA**<br><br>234 (0xEA) | More data is available. This value is returned if the buffer pointed to by *lpszName* is not big enough to hold the result. The *lpcchName* parameter returns the number of characters in the result, excluding the terminating **NULL**. |

## Remarks

To use **ClusterNodeEnum**, applications first open a
node enumeration handle by calling
[ClusterNodeOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternodeopenenum) with the
*dwType* parameter set to **CLUSTER_NODE_ENUM_NETINTERFACES**.
For more information, see [Enumerating Objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/enumerating-objects).

Note that the *lpcchName* parameter refers to a count of characters and not a count of
bytes, and that the returned size does not include the terminating **NULL** in the count.
For more information on sizing buffers, see
[Data Size Conventions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-size-conventions).

#### Examples

See [Enumerating Objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/enumerating-objects).

## See also

[ClusterNodeCloseEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternodecloseenum)

[ClusterNodeOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternodeopenenum)

[Node Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/node-management-functions)