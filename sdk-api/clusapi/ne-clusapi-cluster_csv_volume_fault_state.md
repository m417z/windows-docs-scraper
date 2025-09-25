# CLUSTER_CSV_VOLUME_FAULT_STATE enumeration

## Description

Defines the various fault states for a cluster shared volume (CSV).

## Constants

### `VolumeStateNoFaults:0x00000000`

The CSV has no faults.

### `VolumeStateNoDirectIO:0x00000001`

Direct I/O is disabled for the CSV.

### `VolumeStateNoAccess:0x00000002`

The CSV can not be accessed.

### `VolumeStateInMaintenance:0x00000004`

The CSV is in maintenance mode.

### `VolumeStateDismounted:0x00000008`

The CSV is dismounted.

## See also

[CLUS_CSV_VOLUME_INFO](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-clus_csv_volume_info)

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)