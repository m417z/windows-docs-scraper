# OfflineClusterResource function

## Description

Takes a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) offline. The **PCLUSAPI_OFFLINE_CLUSTER_RESOURCE** type defines a pointer to this function.

## Parameters

### `hResource` [in]

Handle to the resource to be taken offline.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function returns one of the following
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_IO_PENDING** | The resource or one of the resources it depends on has returned **ERROR_IO_PENDING** from its [Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine) entry point function. |
| **ERROR_RESOURCE_FAILED** | This system error code is not returned.<br><br>**Windows Server 2008 Datacenter and Windows Server 2008 Enterprise:** The function attempted to take offline a failed resource, so the failed resource has not been transitioned to an offline state. |

## Remarks

When calling **OfflineClusterResource** to offline a failed resource, it returns **ERROR_SUCCESS** instead of **ERROR_RESOURCE_FAILED**, and the resource will transition to the offline state.

Do not call **OfflineClusterResource** from a resource DLL. For more information, see [Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine)

[Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine)

[OnlineClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-onlineclusterresource)

[OpenClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresource)