# CanResourceBeDependent function

## Description

Determines if one [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) can be [dependent](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dependencies) upon another resource. The **PCLUSAPI_CAN_RESOURCE_BE_DEPENDENT** type defines a pointer to this function.

## Parameters

### `hResource` [in]

Handle to the resource in question.

### `hResourceDependent` [in]

Handle to the resource upon which the resource identified by *hResource* may depend.

## Return value

| Return code | Description |
| --- | --- |
| **TRUE** | The resource identified by *hResource* can depend on the resource identified by *hResourceDependent*. |
| **FALSE** | The resource identified by *hResource* cannot depend on the resource identified by *hResourceDependent*. |

## Remarks

With the **CanResourceBeDependent** function, for the resource identified by *hResource* to be dependent on the resource identified by *hResourceDependent*, the following must be true:

* Both resources must be members of the same [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups).
* The resource identified by *hResourceDependent* cannot depend on the resource identified by *hResource*, either directly or indirectly.

Do not call **CanResourceBeDependent** from any resource DLL entry point function. **CanResourceBeDependent** can safely be called from a worker thread. For more information, see [Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

Do not pass LPC and RPC handles to the same function call. Otherwise, the call will raise an RPC exception and can have additional destructive effects. For information on how LPC and RPC handles are created, see [Using Object Handles](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/using-object-handles) and [OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster).

## See also

[AddClusterResourceDependency](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-addclusterresourcedependency)

[OpenClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresource)

[RemoveClusterResourceDependency](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-removeclusterresourcedependency)