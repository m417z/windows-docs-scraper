# DeleteClusterResource function

## Description

Removes an offline [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) from a [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly). The **PCLUSAPI_DELETE_CLUSTER_RESOURCE** type defines a pointer to this function.

## Parameters

### `hResource` [in]

Handle to an offline resource. You must close this handle separately.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as one of these values.

| Return code | Description |
| --- | --- |
| **ERROR_RESOURCE_ONLINE** | Windows Server 2008 R2: The resource identified by *hResource* is not offline currently. |
| **ERROR_INVALID_STATE** | Windows Server 2012: The resource identified by *hResource* is not offline currently. |

## Remarks

**DeleteClusterResource** does not close the resource handle specified by *hResource*. To avoid memory leaks, be sure to close this handle with [CloseClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclusterresource).

Do not call **DeleteClusterResource** from a resource DLL. For more information, see [Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[CloseClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclusterresource)

[CreateClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createclusterresource)

[OpenClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresource)