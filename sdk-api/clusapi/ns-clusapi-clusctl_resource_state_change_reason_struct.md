# CLUSCTL_RESOURCE_STATE_CHANGE_REASON_STRUCT structure

## Description

Sent with the
[CLUSCTL_RESOURCE_STATE_CHANGE_REASON](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-state-change-reason)
control code to provide the reason for a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) state
change.

## Members

### `dwSize`

The size of the structure in bytes.

### `dwVersion`

The version of the structure. Set to
**CLUSCTL_RESOURCE_STATE_CHANGE_REASON_VERSION_1** (1).

### `eReason`

A value of the
[CLUSTER_RESOURCE_STATE_CHANGE_REASON](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_state_change_reason)
enumeration that describes the reason for the state change. The following list lists the possible values.

#### eResourceStateChangeReasonUnknown (0)

This reason code is never sent by the cluster.
[Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls) should use this value to initialize a
local
**CLUSCTL_RESOURCE_STATE_CHANGE_REASON_STRUCT**
structure and to reset the **eReason** member of this structure before returning from
the [Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine)
and [Terminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pterminate_routine) entry point functions. For more
information, see
[CLUSCTL_RESOURCE_STATE_CHANGE_REASON](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-state-change-reason).

#### eResourceStateChangeReasonMove (1)

[Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine) is about to be called because the
[resource's](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) is being moved.

#### eResourceStateChangeReasonFailover (2)

[Terminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pterminate_routine) is about to be called because the
resource's group is being [failed over](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/failover).

#### eResourceStateChangeReasonFailedMove (3)

[Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine) is about to be called because the resource's
group did not successfully complete a move operation.

#### eResourceStateChangeReasonShutdown (4)

[Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine) is about to be called because the
[Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service) is being shut down.

#### eResourceStateChangeReasonRundown (5)

[Terminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pterminate_routine) is about to be called because the Cluster
service has stopped unexpectedly.

## See also

[CLUSTER_RESOURCE_STATE_CHANGE_REASON](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_state_change_reason)

[Utility Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/utility-structures)