typedef enum CLUSTER_SHARED_VOLUME_SNAPSHOT_STATE {
  ClusterSharedVolumeSnapshotStateUnknown,
  ClusterSharedVolumePrepareForHWSnapshot,
  ClusterSharedVolumeHWSnapshotCompleted,
  ClusterSharedVolumePrepareForFreeze
} ;