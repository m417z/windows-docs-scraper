# SetClusterGroupNodeList function

## Description

Sets the preferred [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) list for a [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups). The **PCLUSAPI_SET_CLUSTER_GROUP_NODE_LIST** type defines a pointer to this function.

## Parameters

### `hGroup` [in]

Handle to the group to be assigned the list of nodes.

### `NodeCount` [in]

Count of nodes in the list identified by *NodeList*.

### `NodeList` [in]

Array of handles to nodes, in order by preference, with the first node being the most preferred and the last node the least preferred. The number of nodes in the *NodeList* array is controlled by the *NodeCount* parameter.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

Do not call **SetClusterGroupNodeList** from a resource DLL. For more information, see [Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

Do not pass LPC and RPC handles to the same function call. Otherwise, the call will raise an RPC exception and can have additional destructive effects. For information on how LPC and RPC handles are created, see [Using Object Handles](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/using-object-handles) and [OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster).

## See also

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)

[OpenClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclustergroup)

[OpenClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternode)