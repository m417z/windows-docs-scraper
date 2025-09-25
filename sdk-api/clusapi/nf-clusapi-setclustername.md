# SetClusterName function

## Description

Sets the name for a [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly). The **PCLUSAPI_SetClusterName** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

Handle to a cluster to rename.

### `lpszNewClusterName` [in]

Pointer to a null-terminated Unicode string containing the new cluster name.

## Return value

If the operation succeeds, the function returns **ERROR_RESOURCE_PROPERTIES_STORED**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The cluster name is stored in the [Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-names-name) private property of the core [Network Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-name) resource (that is, the Network Name resource of the cluster). Because of possible dependencies on this resource, the change is not effective until the Network Name resource is brought back online.

Do not call **SetClusterName** from a resource DLL. For more information, see [Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-names-name)