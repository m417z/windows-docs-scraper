# GetClusterFromGroupSet function

## Description

Returns a handle to the [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) associated with a [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) set. The **PCLUSAPI_GET_CLUSTER_FROM_GROUP_GROUPSET** type defines a pointer to this function.

## Parameters

### `hGroupSet` [in] [in]

A handle to the collection to be deleted

## Return value

If the operation succeeds, the function returns a handle to the cluster that owns the group.

If the operation fails,
the function returns **NULL**. For more information about the error, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).