typedef enum _CLUSTER_SHARED_VOLUME_STATE {
  SharedVolumeStateUnavailable = 0,
  SharedVolumeStatePaused = 1,
  SharedVolumeStateActive = 2,
  SharedVolumeStateActiveRedirected = 3,
  SharedVolumeStateActiveVolumeRedirected = 4
} CLUSTER_SHARED_VOLUME_STATE, *PCLUSTER_SHARED_VOLUME_STATE;