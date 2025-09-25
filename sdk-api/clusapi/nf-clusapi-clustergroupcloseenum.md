# ClusterGroupCloseEnum function

## Description

Closes a [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) enumeration handle. The **PCLUSAPI_CLUSTER_GROUP_CLOSE_ENUM** type defines a pointer to this function.

## Parameters

### `hGroupEnum` [in]

Enumeration handle to close.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[ClusterGroupEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clustergroupenum)

[ClusterGroupOpenEnum](https://learn.microsoft.com/windows/win32/api/clusapi/nf-clusapi-clustergroupopenenum)