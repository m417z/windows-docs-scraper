typedef enum _VDS_DISK_OFFLINE_REASON {
  VDSDiskOfflineReasonNone = 0,
  VDSDiskOfflineReasonPolicy = 1,
  VDSDiskOfflineReasonRedundantPath = 2,
  VDSDiskOfflineReasonSnapshot = 3,
  VDSDiskOfflineReasonCollision = 4,
  VDSDiskOfflineReasonResourceExhaustion = 5,
  VDSDiskOfflineReasonWriteFailure = 6,
  VDSDiskOfflineReasonDIScan = 7,
  VDSDiskOfflineReasonLostDataPersistence = 8
} VDS_DISK_OFFLINE_REASON;