# PQUORUM_RESOURCE_LOST callback function

## Description

Called when control of the [quorum resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/quorum-resource) has
been lost. The **PQUORUM_RESOURCE_LOST** type defines a pointer to this
function.

## Parameters

### `Resource`

#### - ResourceHandle [in]

Handle identifying the [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) to which this callback
applies. The value for *ResourceHandle* should be the handle passed in during the
[Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine) call for this resource.

## Remarks

The *QuorumResourceLost* callback function is
called by a [resource DLL](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls) to notify the
[Resource Monitor](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-monitor) that control of the quorum resource has
been lost after arbitration. A pointer to the Resource Monitor's
*QuorumResourceLost* callback function is passed to
a quorum resource DLL in the call to [Arbitrate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-parbitrate_routine).

## See also

[Arbitrate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-parbitrate_routine)

[Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine)

[Resource DLL Callback Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-callback-functions)