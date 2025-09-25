# ClusterIsPathOnSharedVolume function

## Description

Determines whether a path is on a cluster shared volume (CSV). This is used to determine whether [ClusterGetVolumeNameForVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clustergetvolumenameforvolumemountpoint) or [ClusterGetVolumePathName](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clustergetvolumepathname) should be called instead of [GetVolumeNameForVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumenameforvolumemountpointw) or [GetVolumePathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumepathnamew). The **PCLUSTER_IS_PATH_ON_SHARED_VOLUME** type defines a pointer to this function.

## Parameters

### `lpszPathName` [in]

A pointer to the input path string.

## Return value

**TRUE** if the path is on a CSV and this function is called from a domain account, or if the path is on a CSV that is owned by a local cluster node; otherwise, **FALSE**.

## Remarks

The
**ClusterIsPathOnSharedVolume**
function must be called from a node of the cluster.

The following table explains the possible return values based on the type of cluster node that owns the CSV and the type of user account that calls this function.

|  | User Account Type | |
| --- | --- | --- |
| CSV Ownership | Local | Domain |
| Local Cluster Node | **TRUE** | **TRUE** |
| Other Cluster Node | **FALSE** | **TRUE** |

## See also

[Backing Up and Restoring the Failover Cluster Configuration Using VSS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/backing-up-and-restoring-the-failover-cluster-configuration-using-vss)

[Backup and Restore Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/backup-and-restore-functions)

[GetVolumePathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumepathnamew)