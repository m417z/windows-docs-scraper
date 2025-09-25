# CLUS_MAINTENANCE_MODE_INFOEX structure

## Description

Represents the extended maintenance mode settings for a storage class resource.

## Members

### `InMaintenance`

Set to **TRUE** to enable or **FALSE** to disable maintenance
mode for the identified resource.
When queried, a resource will return **True** or **False** to
indicate the current maintenance mode state of the resource.

### `MaintainenceModeType`

Unless the resource in question is in a type of maintenance mode, this member is set to 0. Otherwise this member takes an **enumerator** from the [MAINTENANCE_MODE_TYPE_ENUM](https://learn.microsoft.com/windows/desktop/api/clusapi/ne-clusapi-maintenance_mode_type_enum) enumeration as its value. The possible values of this member are as follows.

#### 0

The resource is not in maintenance mode.

#### MaintenanceModeTypeDisableIsAliveCheck (1)

Indicates that the server is ignoring the result of the resource's health check.

#### MaintenanceModeTypeOfflineResource (2)

Indicates that the server has internally performed the operations to bring the storage resource to the ClusterResourceOffline state without changing the client visible state of the resource.

#### MaintenanceModeTypeUnclusterResource (3)

Indicates the server has released ownership of the storage resource.

### `InternalState`

This member represents the internal resource state. This field is valid only when written by the server. This member takes an enumerator from the [CLUSTER_RESOURCE_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_state) enumeration. The possible values of this member are as follows.

#### ClusterResourceStateUnknown (–1)

The operation was not successful. For more information about the error, call the function
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

#### ClusterResourceInitializing (1)

The resource is performing initialization.

#### ClusterResourceOnline (2)

The resource is operational and functioning normally.

#### ClusterResourceOffline (3)

The resource is not operational.

#### ClusterResourceFailed (4)

The resource has [failed](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/f-gly).

#### ClusterResourceOnlinePending (129)

The resource is in the process of coming online.

#### ClusterResourceOfflinePending (130)

The resource is in the process of going offline.

### `Signature`

A 32-bit integer that must contain the value 0xABBAF00F.

## See also

[CLUSTER_RESOURCE_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_state)

[MAINTENANCE_MODE_TYPE_ENUM](https://learn.microsoft.com/windows/desktop/api/clusapi/ne-clusapi-maintenance_mode_type_enum)

[Utility structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/utility-structures)