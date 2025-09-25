# RemoveClusterResourceDependency function

## Description

Removes a [dependency](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dependencies) relationship between two [resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources). The **PCLUSAPI_REMOVE_CLUSTER_RESOURCE_DEPENDENCY** type defines a pointer to this function.

## Parameters

### `hResource` [in]

Handle to the dependent resource.

### `hDependsOn` [in]

Handle to the resource that the resource identified by *hResource* currently depends on.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

Do not call **RemoveClusterResourceDependency** from a resource DLL. For more information, see [Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

Do not pass LPC and RPC handles to the same function call. Otherwise, the call will raise an RPC exception and can have additional destructive effects. For information on how LPC and RPC handles are created, see [Using Object Handles](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/using-object-handles) and [OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster).

## See also

[AddClusterResourceDependency](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-addclusterresourcedependency)

[CanResourceBeDependent](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-canresourcebedependent)

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)

[OpenClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresource)