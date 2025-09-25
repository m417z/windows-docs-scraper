# PSET_RESOURCE_STATUS_ROUTINE callback function

## Description

Called to update the status of a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources).
The **PSET_RESOURCE_STATUS_ROUTINE** type defines a pointer to this function.

## Parameters

### `ResourceHandle` [in]

Handle identifying the resource to be updated. The *ResourceHandle* parameter should
contain the same handle used for the *ResourceHandle* parameter in the
[Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine) entry point for this resource.

### `ResourceStatus` [in]

Pointer to a [RESOURCE_STATUS](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resource_status) structure that
contains information about the resource's state.

## Return value

*SetResourceStatus* returns one of
the following values enumerated from the
[RESOURCE_EXIT_STATE](https://learn.microsoft.com/windows/desktop/api/resapi/ne-resapi-resource_exit_state) enumeration.

| Return code/value | Description |
| --- | --- |
| **ResourceExitStateContinue**<br><br>0 | The resource has not been terminated. Worker threads may continue [Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine) and [Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine) operations for the resource. |
| **ResourceExitStateTerminate**<br><br>1 | The resource has been terminated. Callers should end [Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine) or [Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine) operations and immediately terminate all worker threads assigned to the resource. |

## Remarks

[Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls) call the
*SetResourceStatus* callback function to update the
status of a resource after their [Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine) or
[Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine) entry point function has returned
**ERROR_IO_PENDING**. It should not be called at any other time. A pointer to the
*SetResourceStatus* function is passed in the
*SetResourceStatus* parameter to the resource's implementation of
[Startup](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pstartup_routine).

*SetResourceStatus* is implemented by the
[Resource Monitor](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-monitor) and is similar to the
[SetServiceStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setservicestatus) function.

Update the current state of a resource whenever necessary after you have returned
**ERROR_IO_PENDING**. If the resource is in one of the pending states, increment the values
for the **CheckPoint** and **WaitHint** members of the
[RESOURCE_STATUS](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resource_status) structure and set the
**ResourceState** member to **ClusterResourceOnlinePending** or
**ClusterResourceOfflinePending** before you begin calling
*SetResourceStatus*. Call
*SetResourceStatus* until one of the following
situations occurs:

* The resource is placed in either the **ClusterResourceOnline** or
  **ClusterResourceOffline** state.
* The time limit stored in the resource's
  [PendingTimeout](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources-pendingtimeout) property has been
  exceeded.

There is no need to call
*SetResourceStatus* to set the state of a resource to
a pending state because the Resource Monitor automatically sets it to the appropriate pending state whenever
[Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine) or
[Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine) returns
**ERROR_IO_PENDING**.

## See also

[ClusWorkerTerminate](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clusworkerterminate)

[Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine)

[Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine)

[Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine)

[RESOURCE_EXIT_STATE](https://learn.microsoft.com/windows/desktop/api/resapi/ne-resapi-resource_exit_state)

[RESOURCE_STATUS](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resource_status)

[Resource DLL Callback Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-callback-functions)

[SetServiceStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setservicestatus)

[Startup](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pstartup_routine)

[Terminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pterminate_routine)