# MAINTENANCE_MODE_TYPE_ENUM enumeration

## Description

Defines the possible states that a storage class resource can be placed in when marked for maintenance.

## Constants

### `MaintenanceModeTypeDisableIsAliveCheck:1`

Indicates that the server is ignoring the result of the resource's health check.

### `MaintenanceModeTypeOfflineResource:2`

Indicates that the server has internally performed the operations to bring the storage resource to the ClusterResourceOffline state without changing the client visible state of the resource.

### `MaintenanceModeTypeUnclusterResource:3`

Indicates the server has released ownership of the storage resource.

## See also

[CLUS_MAINTENANCE_MODE_INFOEX](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-clus_maintenance_mode_infoex)

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)

[MaintenanceMode](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/maintenancemode)