# RESOURCE_EXIT_STATE enumeration

## Description

Enumerates the possible exit states of a
[resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources). These values are returned by the
[SetResourceStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pset_resource_status_routine) callback function.

## Constants

### `ResourceExitStateContinue`

The resource has not been terminated. Worker threads may continue
[Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine) and
[Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine) operations for the resource.

### `ResourceExitStateTerminate`

The resource has been terminated. Callers should end
[Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine) or
[Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine) operations and immediately terminate all worker
threads assigned to the resource.

### `ResourceExitStateMax`

This value is only used for comparisons. All supported values are less than
**ResourceExitStateMax**.

## See also

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)

[SetResourceStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pset_resource_status_routine)