# POPEN_V2_ROUTINE callback function

## Description

Opens a
[resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources). The
**POPEN_V2_ROUTINE** type defines a pointer to this function.

## Parameters

### `ResourceName` [in]

The name of the resource to open.

### `ResourceKey` [in]

The [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) key for the
cluster that includes the resource represented by
*ResourceName*.

### `ResourceHandle` [in]

The resource handle to pass to the [SetResourceStatusEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pset_resource_status_routine_ex)
callback function.

### `OpenFlags` [in] [in]

One of the following flags:

#### 0x0

TBD

#### CLUS_RESDLL_OPEN_RECOVER_MONITOR_STATE (0x00000001)

TBD

## Return value

If the operation was successful, returns a resource
identifier (**RESID**).

If the operation was not successful, returns
**NULL**. Call [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) to
specify that an error has occurred.

## See also

[Resource DLL Entry-Point Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-entry-point-functions)