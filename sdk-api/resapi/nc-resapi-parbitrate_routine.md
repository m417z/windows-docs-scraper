# PARBITRATE_ROUTINE callback function

## Description

Allows a [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) to attempt to regain ownership of a
[quorum resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/quorum-resource). The
**PARBITRATE_ROUTINE** type defines a pointer to this function.

## Parameters

### `Resource` [in]

Resource identifier for the quorum resource to be owned.

### `LostQuorumResource` [in]

Address of a [QuorumResourceLost](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pquorum_resource_lost) callback
function that should be called if control of the quorum resource is lost after being successfully gained.

## Return value

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The arbitration was successful and the quorum resource remains defended. |
| **[Error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes)** | The arbitration was not successful. |

## Remarks

The *Arbitrate* entry-point function is implemented for
[quorum resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/quorum-resource) only. Expect this function to
be called only after both [Startup](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pstartup_routine) and
[Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine) have been called.

Implementations of **Arbitrate** should take less than 300
milliseconds to complete.

If **Arbitrate** is successful, make sure that only the
current node can successfully arbitrate for the quorum resource represented by
*ResourceId*. For example, a disk resource can implement a defense by continually
replacing the reservation made on it once per second.

## See also

[Resource DLL Entry-Point Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-entry-point-functions)