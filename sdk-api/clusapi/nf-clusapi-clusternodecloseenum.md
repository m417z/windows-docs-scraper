# ClusterNodeCloseEnum function

## Description

Closes a [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) enumeration handle. The **PCLUSAPI_CLUSTER_NODE_CLOSE_ENUM** type defines a pointer to this function.

## Parameters

### `hNodeEnum` [in]

Handle to the node enumerator to close. This is a handle originally returned by the [ClusterNodeOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternodeopenenum) function.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.
If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[ClusterNodeEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternodeenum)

[ClusterNodeOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternodeopenenum)

[Node Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/node-management-functions)