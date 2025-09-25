# PIS_ALIVE_ROUTINE callback function

## Description

Determines whether a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) is available for
use. The **PIS_ALIVE_ROUTINE** type defines a pointer to this function.

## Parameters

### `Resource` [in]

Resource identifier for the resource to poll.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE**<br><br>1 | The resource is online and functioning properly. |
| **FALSE**<br><br>0 | The resource is not functioning properly. |

## Remarks

For effective implementation strategies of the *IsAlive*
entry-point function, see [Implementing IsAlive](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/implementing-isalive).

#### Examples

See [Resource DLL Examples](https://learn.microsoft.com/previous-versions/aa372246(v=vs.85)).

## See also

[NetShareGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharegetinfo)

[Resource DLL Entry-Point Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-entry-point-functions)