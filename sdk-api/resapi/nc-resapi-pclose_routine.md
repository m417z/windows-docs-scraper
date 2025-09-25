# PCLOSE_ROUTINE callback function

## Description

Closes a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources). The
**PCLOSE_ROUTINE** type defines a pointer to this function.

## Parameters

### `Resource`

#### - ResourceId [in]

Resource identifier of the resource to close.

## Return value

None. Call [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) to specify that an error has
occurred.

## Remarks

For effective implementation strategies of the **Close**
entry-point function, see
[Implementing Close](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/implementing-close).

#### Examples

See [Resource DLL Examples](https://learn.microsoft.com/previous-versions/aa372246(v=vs.85)).

## See also

[Resource DLL Entry-Point Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-entry-point-functions)