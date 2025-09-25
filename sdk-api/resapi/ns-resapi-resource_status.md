# RESOURCE_STATUS structure

## Description

Contains information
about a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) that is being brought online or taken offline.
This structure is used as a parameter to the callback function
[SetResourceStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pset_resource_status_routine).

## Members

### `ResourceState`

A value describing the state of a resource enumerated by the
[CLUSTER_RESOURCE_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_state) enumeration. The possible values for this member are as follows:

#### ClusterResourceStateUnknown (-1)

An error occurred while trying to retrieve the state, typically because the server is no longer available.
For more information, the caller should call the function
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

#### ClusterResourceOnline (2)

The resource is online and available.

#### ClusterResourceOffline (3)

The resource is offline and unavailable.

#### ClusterResourceFailed (4)

The resource has failed.

#### ClusterResourceOnlinePending (129)

The resource is in the process of being placed online. The **CheckPoint** member
should be greater than the previous value of this member.

#### ClusterResourceOfflinePending (130)

The resource is in the process of being taken offline.

### `CheckPoint`

A value set by the [resource DLL](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls) to flag a status
report as new.

### `WaitHint`

This member is not being used at this time.

### `EventHandle`

Handle to an event that indicates when the resource has failed.

## Remarks

Resource DLLs typically set the **ResourceState** member to
**ClusterResourceOnline** or **ClusterResourceOffline**. However,
if **ResourceState** is set to **ClusterResourceOnlinePending** or
**ClusterResourceOfflinePending**, the **CheckPoint** member
should be greater than the previous value reported for **CheckPoint**.

Resource DLLs initially set **CheckPoint** to zero, then increment it by 1 for each call
to [SetResourceStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pset_resource_status_routine).
[Resource Monitors](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-monitor) detect new status reports by comparing
the current value of **CheckPoint** to the previous value. If the value has changed, the
Resource Monitor reads the new status information.

Before returning the **ClusterResourceUnknown** state in the
**ResourceState** member, a resource DLL should call the function
[SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror).

Resource DLLs set the **EventHandle** member to a handle that is signaled when a
resource fails.

For more information, see
[Implementing Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/implementing-resource-dlls).

## See also

[CLUSTER_RESOURCE_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_state)

[Resource DLL Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-structures)

[SetResourceStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pset_resource_status_routine)