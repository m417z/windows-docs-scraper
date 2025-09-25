# ClusterClearBackupStateForSharedVolume function

## Description

Clears the backup state for the cluster shared volume (CSV). The **PCLUSTER_CLEAR_BACKUP_STATE_FOR_SHARED_VOLUME** type defines a pointer to this function.

## Parameters

### `lpszVolumePathName` [in]

Path to a file on a CSV. If the path is not a CSV path,
**ClusterClearBackupStateForSharedVolume**
will return **ERROR_INVALID_PARAMETER** (87).

## Return value

If the function succeeds, it returns **ERROR_SUCCESS** (0).

If the function fails, it returns one of the
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The
**ClusterClearBackupStateForSharedVolume**
function must be called from a node of the cluster.

Normally, when a backup job completes, the CSV "Backup in Progress" state (set by
[ClusterPrepareSharedVolumeForBackup](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clusterpreparesharedvolumeforbackup))
is automatically cleared—meaning that the CSV volume is unpinned from this Cluster node and
direct I/O is re-enabled. If the backup process is terminated after the call to
**ClusterPrepareSharedVolumeForBackup**
and before the snapshot creation process is complete, CSV will wait 30 minutes before it will clear the
"Backup in Progress" state. If the requester is able to safely determine that no other backups
are active on this CSV,
**ClusterClearBackupStateForSharedVolume**
may be called to clear the "Backup in Progress" state of the CSV volume.

**Note** When the
**ClusterClearBackupStateForSharedVolume**
function is called for a particular CSV volume, the Backup State for that CSV is cleared without regard to other
backups that could be active on any node within the Cluster. To avoid corruption of an in-progress backup,
extreme care must be taken to ensure that there are no other backups active for this CSV volume before
calling
**ClusterClearBackupStateForSharedVolume**.

## See also

[Backing Up and Restoring the Failover Cluster Configuration Using VSS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/backing-up-and-restoring-the-failover-cluster-configuration-using-vss)

[Backup and Restore Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/backup-and-restore-functions)

[CLUSCTL_RESOURCE_SET_SHARED_VOLUME_BACKUP_MODE](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-set-shared-volume-backup-mode)

[GetVolumePathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumepathnamew)