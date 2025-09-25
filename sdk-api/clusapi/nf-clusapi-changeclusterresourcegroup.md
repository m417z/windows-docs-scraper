# ChangeClusterResourceGroup function

## Description

Moves a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) from one
[group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) to another. The
**PCLUSAPI_CHANGE_CLUSTER_RESOURCE_GROUP** type defines a pointer to this function.

## Parameters

### `hResource` [in]

Handle of the resource to be moved.

### `hGroup` [in]

Handle of the group that should receive the resource identified by
*hResource*.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

With the **ChangeClusterResourceGroup**
function, both the group that a resource currently belongs to and its new group must be owned by the same
[node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) regardless of the resource's state.

Do not call **ChangeClusterResourceGroup**
from a resource DLL. For more information, see
[Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).
If the resource identified by *hResource* has
[dependencies](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dependencies), all of the resources in its dependency
tree are moved to the group identified by *hGroup*. For example, in the situation shown
in the following diagram, changing resource B to group 2 will move the entire dependency tree (resources A, X, and
Y) .

:::image type="content" source="./images/resmove.png" border="false" alt-text="Diagram showing the tree of dependencies between resources in a Cluster Resource Group, before and after a resource is moved to another group.":::

Do not pass LPC and RPC handles to the same function call. Otherwise, the call will raise an RPC exception and
can have additional destructive effects. For information on how LPC and RPC handles are created, see
[Using Object Handles](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/using-object-handles) and
[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster).

## See also

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)

[OpenClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclustergroup)

[OpenClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresource)