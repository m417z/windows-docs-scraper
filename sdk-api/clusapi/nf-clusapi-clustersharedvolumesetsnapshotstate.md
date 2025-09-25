# ClusterSharedVolumeSetSnapshotState function

## Description

Updates the state of a snapshot of a cluster shared volume.

## Parameters

### `guidSnapshotSet` [in]

The **GUID** of the snapshot.

### `lpszVolumeName` [in]

A pointer to the name of the cluster shared volume.

### `state` [in]

A [CLUSTER_SHARED_VOLUME_SNAPSHOT_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_shared_volume_snapshot_state) enumeration value that specifies the state of the snapshot.

## Return value

If the operation succeeds, the function returns a resource handle.

If the operation fails, the function returns **NULL**. For more information about the
error, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Failover Cluster Resource Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-management-functions)