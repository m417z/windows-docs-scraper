# PLOOKS_ALIVE_ROUTINE callback function

## Description

Determines whether a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) appears to be available
for use. The **PLOOKS_ALIVE_ROUTINE** type defines a pointer to this
function.

## Parameters

### `Resource` [in]

Resource identifier for the resource to poll.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE**<br><br>1 | The resource is probably online and available for use. |
| **FALSE**<br><br>0 | The resource may not be functioning properly. |

## Remarks

For effective implementation strategies of the
*LooksAlive* entry-point function, see
[Implementing LooksAlive](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/implementing-looksalive).

#### Examples

See [Resource DLL Examples](https://learn.microsoft.com/previous-versions/aa372246(v=vs.85)).

## See also

[Resource DLL Entry-Point Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-entry-point-functions)