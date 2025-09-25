# POPEN_ROUTINE callback function

## Description

Opens a
[resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources). The
**POPEN_ROUTINE** type defines a pointer to this function.

## Parameters

### `ResourceName` [in]

Name of the resource to open.

### `ResourceKey` [in]

[Cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) key for the
[cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) that includes the resource represented by
*ResourceName*.

### `ResourceHandle` [in]

Handle to be passed to the [SetResourceStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pset_resource_status_routine)
callback function in the [Startup](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pstartup_routine) entry-point function.

## Return value

If the operation was successful, *Open* returns a resource
identifier (**RESID**).

If the operation was not successful, *Open* returns
**NULL**. Call [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) to
specify that an error has occurred.

## Remarks

The *Open* entry-point function opens a resource with the name
identified by the *ResourceName* parameter and returns its resource identifier. The
resource identifier can be used in future calls to other
[Resource API](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-api) entry points to identify the resource.

Never close the handle represented by the *ResourceHandle* parameter or use it for any
purpose other than passing it to the [Resource Monitor](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-monitor)
through either the [LogEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-plog_event_routine) callback function or the
[SetResourceStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pset_resource_status_routine) callback function.

For effective implementation strategies of the *Open*
entry-point function, see [Implementing Open](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/implementing-open).

#### Examples

See [Resource DLL Examples](https://learn.microsoft.com/previous-versions/aa372246(v=vs.85)).

## See also

[LogEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-plog_event_routine)

[Resource DLL Entry-Point Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-entry-point-functions)

[SetResourceStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pset_resource_status_routine)