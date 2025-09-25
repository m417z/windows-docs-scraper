# GetClusterNodeId function

## Description

Returns the unique identifier of a cluster
[node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes). The **PCLUSAPI_GET_CLUSTER_NODE_ID** type defines a pointer to this function.

## Parameters

### `hNode` [in, optional]

Handle to the node with the identifier to be returned or **NULL**. If
*hNode* is set to **NULL**, the node identifier for the node on
which the application is running is returned in the content of *lpszNodeId*.

### `lpszNodeId` [out]

This parameter points to a buffer that receives the unique ID of *hNode*, including
the terminating **NULL** character.

### `lpcchName` [in, out]

On input, pointer to the count of characters in the buffer pointed to by the
*lpszNodeId* parameter, including the **NULL** terminator. On
output, pointer to the count of characters stored in the buffer excluding the **NULL**
terminator.

## Return value

This function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following are the
possible values:

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The operation completed successfully. |
| **ERROR_MORE_DATA**<br><br>234 (0xEA) | More data is available. This value is returned if the buffer pointed to by *lpszNodeId* is not long enough to hold the required number of characters. [GetClusterNodeId](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternodeid) sets the content of *lpcchName* to the required length. |

## Remarks

The **PCLUSAPI_GET_CLUSTER_NODE_ID** type defines a pointer to this function.

If *hNode* is set to **NULL** and the caller is running on an
active cluster node, the **GetClusterNodeId** function
returns the identifier of the node on which the application is running. Setting *hNode*
to **NULL** is a convenient way for
[resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls) to determine the node identifier of the node
they are running on. The [GetCurrentClusterNodeId](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-getcurrentclusternodeid)
macro can be used instead of passing **NULL** for the *hNode*
parameter.

A cluster node identifier is a unique identifier that does not change even if the node's name is changed.

Note that *lpcchName* refers to a count of characters and not a count of bytes, and
that the returned size does not include the terminating **NULL** in the count. For more information on sizing
buffers, see [Data Size Conventions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-size-conventions).

## See also

[GetCurrentClusterNodeId](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-getcurrentclusternodeid)

[Node Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/node-management-functions)

[OpenClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternode)