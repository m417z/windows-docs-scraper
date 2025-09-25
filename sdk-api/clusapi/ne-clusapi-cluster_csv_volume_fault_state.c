typedef enum _CLUSTER_CSV_VOLUME_FAULT_STATE {
  VolumeStateNoFaults = 0x00000000,
  VolumeStateNoDirectIO = 0x00000001,
  VolumeStateNoAccess = 0x00000002,
  VolumeStateInMaintenance = 0x00000004,
  VolumeStateDismounted = 0x00000008
} CLUSTER_CSV_VOLUME_FAULT_STATE, *PCLUSTER_CSV_VOLUME_FAULT_STATE;