typedef enum CLUSTER_SHARED_VOLUME_SNAPSHOT_STATE {
  ClusterSharedVolumeSnapshotStateUnknown = 0,
  ClusterSharedVolumePrepareForHWSnapshot,
  ClusterSharedVolumeHWSnapshotCompleted,
  ClusterSharedVolumePrepareForFreeze
} ;