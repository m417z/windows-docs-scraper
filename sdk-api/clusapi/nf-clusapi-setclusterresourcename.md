# SetClusterResourceName function

## Description

Sets the name for a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources). The
**PCLUSAPI_SET_CLUSTER_RESOURCE_NAME** type defines a pointer to this function.

## Parameters

### `hResource` [in]

Handle to a resource to rename.

### `lpszResourceName` [in]

Pointer to the new name for the resource identified by *hResource*. Resource names
are not case sensitive. A resource name must be unique within the cluster.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

**SetClusterResourceName** changes the
[Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources-name) common property of the resource identified by
*hResource*. This is the only way that
**Name**, a read-only property, can be changed.

Do not call **SetClusterResourceName** from a
resource DLL. For more information, see
[Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources-name)

[OpenClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresource)