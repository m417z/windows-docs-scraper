# AddClusterResourceDependency function

## Description

Creates a [dependency](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dependencies) relationship between two
[resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources). The **PCLUSAPI_ADD_CLUSTER_RESOURCE_DEPENDENCY** type defines a pointer to this function.

## Parameters

### `hResource` [in]

Handle to the dependent resource.

### `hDependsOn` [in]

Handle to the resource that the resource identified by *hResource* should depend
on.

## Return value

If the operation succeeds, it returns **ERROR_SUCCESS** (0).

If the operation fails,
**AddClusterResourceDependency** returns
one of the [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following are
possible return values.

| Return code/value | Description |
| --- | --- |
| **ERROR_CIRCULAR_DEPENDENCY**<br><br>1059 (0x423) | A resource depends on itself. |
| **ERROR_DEPENDENCY_ALREADY_EXISTS**<br><br>5003 (0x138B) | The resource dependency already exists. |
| **ERROR_DEPENDENCY_NOT_ALLOWED**<br><br>5069 (0x13CD) | The dependent resource is the quorum. |
| **ERROR_INVALID_PARAMETER**<br><br>87 (0x57) | The resources are not in the same group. |
| **ERROR_RESOURCE_NOT_AVAILABLE**<br><br>5006 (0x138E) | At least one of the resources is marked for deletion. |
| **ERROR_RESOURCE_ONLINE**<br><br>5019 (0x139B) | The dependent resource is already online. |

## Remarks

A dependency relationship created by the
**AddClusterResourceDependency** function
affects how resources are moved from one [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) to another after a
[failure](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-failure). It determines the order in which resources are
taken offline and brought back online.

Resources in a dependency relationship must be moved together. The dependent resource must be brought online
after the resource upon which it depends.

The two resources identified by *hResource* and *hDependsOn*
must be in the same group.

Do not call
**AddClusterResourceDependency** if
*hResource* is already online. The call fails with an
**ERROR_RESOURCE_ONLINE** error. Note that this behavior has changed with Windows Server 2008. You can call **AddClusterResourceDependency** and modify resource dependencies without requiring the resource to be brought offline.

Do not call
**AddClusterResourceDependency** from a
resource DLL. For more information, see
[Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

Do not pass LPC and RPC handles to the same function call. Otherwise, the call will raise an RPC exception and
can have additional destructive effects. For information on how LPC and RPC handles are created, see
[Using Object Handles](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/using-object-handles) and
[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster).

## See also

[CanResourceBeDependent](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-canresourcebedependent)

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)

[OpenClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresource)

[RemoveClusterResourceDependency](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-removeclusterresourcedependency)