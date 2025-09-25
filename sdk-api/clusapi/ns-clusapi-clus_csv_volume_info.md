# CLUS_CSV_VOLUME_INFO structure

## Description

Represents information about a cluster shared volume (CSV).

## Members

### `VolumeOffset`

The physical offset, in bytes, of the data on the CSV.

### `PartitionNumber`

The partition number of the CSV.

### `FaultState`

A [CLUSTER_CSV_VOLUME_FAULT_STATE](https://learn.microsoft.com/windows/desktop/api/clusapi/ne-clusapi-cluster_csv_volume_fault_state) enumeration value that specifies the fault state of the CSV.

### `BackupState`

A [CLUSTER_SHARED_VOLUME_BACKUP_STATE](https://learn.microsoft.com/windows/desktop/api/clusapi/ne-clusapi-cluster_shared_volume_backup_state) enumeration value that specifies the state of the CSV backup.

### `szVolumeFriendlyName`

The friendly name of the CSV.

### `szVolumeName`

The volume **GUID** path of the CSV.

## See also

[Data structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)