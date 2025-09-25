# CLUS_SHARED_VOLUME_BACKUP_MODE structure

## Description

Describes the backup mode for cluster shared volume (CSV). Used by the
[CLUSCTL_RESOURCE_SET_SHARED_VOLUME_BACKUP_MODE](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-set-shared-volume-backup-mode) [control code](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/about-control-codes).

## Members

### `BackupState`

Value from
[CLUSTER_SHARED_VOLUME_BACKUP_STATE](https://learn.microsoft.com/windows/desktop/api/clusapi/ne-clusapi-cluster_shared_volume_backup_state)
enumeration.

#### VolumeBackupNone (0)

There is no backup in progress for this CSV.

#### VolumeBackupInProgress (1)

There is a backup in progress for this CSV.

### `DelayTimerInSecs`

If the **BackupState** member is set to **VolumeBackupNone**
then this member must be set to 0. Otherwise this member must be set to a nonzero value.

### `VolumeName`

Null-terminated Unicode string containing the name of the shared volume. The name provided can
be either the cluster-assigned friendly name or the volume GUID path of the form
"\\?\Volume{xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx}\".

## See also

[CLUSCTL_RESOURCE_SET_SHARED_VOLUME_BACKUP_MODE](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-set-shared-volume-backup-mode)

[CLUSTER_SHARED_VOLUME_BACKUP_STATE](https://learn.microsoft.com/windows/desktop/api/clusapi/ne-clusapi-cluster_shared_volume_backup_state)

[Data Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)