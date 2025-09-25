# OfflineClusterGroup function

## Description

Takes a [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) offline. The **PCLUSAPI_OFFLINE_CLUSTER_GROUP** type defines a pointer to this function.

## Parameters

### `hGroup` [in]

Handle to the group to be taken offline.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is one of the possible error codes.

| Return code | Description |
| --- | --- |
| **ERROR_IO_PENDING** | The operation is in progress. |

## Remarks

Do not call **OfflineClusterGroup** from a resource DLL. For more information, see [Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[OnlineClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-onlineclustergroup)

[OpenClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclustergroup)