# RemoveClusterResourceNode function

## Description

Removes a [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) from the list of nodes that can host a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources). The **PCLUSAPI_REMOVE_CLUSTER_RESOURCE_NODE** type defines a pointer to this function.

## Parameters

### `hResource` [in]

Handle to the target resource.

### `hNode` [in]

Handle to the node that should be removed from the list of potential host nodes belonging to the resource identified by *hResource*.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

Do not call **RemoveClusterResourceNode** from a resource DLL. For more information, see [Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

Do not pass LPC and RPC handles to the same function call. Otherwise, the call will raise an RPC exception and can have additional destructive effects. For information on how LPC and RPC handles are created, see [Using Object Handles](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/using-object-handles) and [OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster).

## See also

[AddClusterResourceNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-addclusterresourcenode)

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)

[OpenClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternode)

[OpenClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresource)