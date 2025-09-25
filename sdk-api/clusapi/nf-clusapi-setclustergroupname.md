# SetClusterGroupName function

## Description

Sets the name for a [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups). The **PCLUSAPI_SET_CLUSTER_GROUP_NAME** type defines a pointer to this function.

## Parameters

### `hGroup` [in]

Handle to the group to name.

### `lpszGroupName` [in]

Pointer to the new name for the group identified by *hGroup*.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

**SetClusterGroupName** changes the
[Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups-name) common property of the group identified by
*hGroup*. This is the only way that Name, a read-only property, can be changed.

Do not call **SetClusterGroupName** from a
resource DLL. For more information, see
[Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups-name)

[OpenClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclustergroup)