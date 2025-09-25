# OnlineClusterResource function

## Description

Brings an offline or failed [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) online. The **PCLUSAPI_ONLINE_CLUSTER_RESOURCE** type defines a pointer to this function.

## Parameters

### `hResource` [in]

Handle to the resource to be brought online.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is a possible error code.

| Return code | Description |
| --- | --- |
| **ERROR_IO_PENDING** | The resource or one of the resources it depends on has returned **ERROR_IO_PENDING** from its [Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine) entry point function. |

## Remarks

Do not call **OnlineClusterResource** from a resource DLL. For more information, see [Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine)

[OfflineClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-offlineclusterresource)

[Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine)

[OpenClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresource)