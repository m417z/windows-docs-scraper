# CLUSTER_RESOURCE_STATE_CHANGE_REASON enumeration

## Description

Used by the
[CLUSCTL_RESOURCE_STATE_CHANGE_REASON_STRUCT](https://learn.microsoft.com/windows/win32/api/clusapi/ns-clusapi-clusctl_resource_state_change_reason_struct)
and
[CLUSCTL_RESOURCE_STATE_CHANGE_REASON](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-state-change-reason)
control codes to describe the reason for a resource state change.

## Constants

### `eResourceStateChangeReasonUnknown`

This reason code is never sent by the cluster.
[Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls) should use this value to initialize a local
[CLUSCTL_RESOURCE_STATE_CHANGE_REASON_STRUCT](https://learn.microsoft.com/windows/win32/api/clusapi/ns-clusapi-clusctl_resource_state_change_reason_struct) structure and to reset the
**eReason** member of the
**CLUSCTL_RESOURCE_STATE_CHANGE_REASON_STRUCT**
structure before returning from the [Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine) and
[Terminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pterminate_routine) entry point functions. For more information,
see
[CLUSCTL_RESOURCE_STATE_CHANGE_REASON](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-state-change-reason).

### `eResourceStateChangeReasonMove`

[Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine) is about to be called because the
[resource's](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) is being moved.

### `eResourceStateChangeReasonFailover`

[Terminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pterminate_routine) is about to be called because the resource's
group is being [failed over](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/failover).

### `eResourceStateChangeReasonFailedMove`

[Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine) is about to be called because the resource's
group did not successfully complete a move operation.

### `eResourceStateChangeReasonShutdown`

[Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine) is about to be called because the
[Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service) is being shut down.

### `eResourceStateChangeReasonRundown`

[Terminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pterminate_routine) is about to be called because the Cluster
service has stopped unexpectedly.

## See also

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)