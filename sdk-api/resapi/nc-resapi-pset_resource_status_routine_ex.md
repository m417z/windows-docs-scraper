# PSET_RESOURCE_STATUS_ROUTINE_EX callback function

## Description

Called to update the status of a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources).
The **PSET_RESOURCE_STATUS_ROUTINE_EX** type defines a pointer to this function.

## Parameters

### `ResourceHandle`

A handle to the resource to be updated. The *ResourceHandle* parameter should
contain the same handle that is used for the *ResourceHandle* parameter in the
[OpenV2](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_v2_routine) entry point for this resource.

### `ResourceStatus`

A pointer to a [RESOURCE_STATUS_EX](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resource_status_ex) structure that
contains information about the resource's state.

## Return value

One of
the following values of the
[RESOURCE_EXIT_STATE](https://learn.microsoft.com/windows/desktop/api/resapi/ne-resapi-resource_exit_state) enumeration.

| Return code/value | Description |
| --- | --- |
| **ResourceExitStateContinue**<br><br>0 | The resource has not been terminated. Worker threads can continue [OnlineV2](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_v2_routine) and [OfflineV2](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_v2_routine) operations for the resource. |
| **ResourceExitStateTerminate**<br><br>1 | The resource has been terminated. Callers should end [OnlineV2](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_v2_routine) or [OfflineV2](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_v2_routine) operations and immediately terminate all worker threads that are assigned to the resource. |

## See also

[Resource DLL Callback Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-callback-functions)