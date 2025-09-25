# PTERMINATE_ROUTINE callback function

## Description

Immediately marks a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) as unavailable for use
without waiting for cleanup processing to be completed. The
**PTERMINATE_ROUTINE** type defines a pointer to this function.

## Parameters

### `Resource` [in]

Resource identifier for the resource to be made unavailable.

## Remarks

The *Terminate* entry-point function instantly marks a
resource as unavailable for use. If there is a thread processing an
[Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine) or
[Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine) request for the resource, these requests are canceled
and the resource is taken offline immediately.

For effective implementation strategies of the *Terminate*
entry-point function, see
[Implementing Terminate](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/implementing-terminate).

#### Examples

See [Resource DLL Examples](https://learn.microsoft.com/previous-versions/aa372246(v=vs.85)).

## See also

[Resource DLL Entry-Point Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-entry-point-functions)