# AddClusterResourceNode function

## Description

Adds a [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) to the list of possible nodes that a
[resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) can run on. The
**PCLUSAPI_ADD_CLUSTER_RESOURCE_NODE** type defines a pointer to this function.

## Parameters

### `hResource` [in]

Handle to a resource that will add a node to its possible owners list.

### `hNode` [in]

Handle to the node to be added to the list of potential host nodes belonging to the resource identified by
*hResource*.

## Return value

If the operation succeeds, it returns **ERROR_SUCCESS**.

If the operation fails,
**AddClusterResourceNode** returns one of the
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

Do not pass LPC and RPC handles to the same function call. Otherwise, the call will raise an RPC exception and
can have additional destructive effects. For information on how LPC and RPC handles are created, see
[Using Object Handles](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/using-object-handles) and
[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster).

## See also

[OpenClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternode)

[OpenClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresource)

[RemoveClusterResourceNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-removeclusterresourcenode)