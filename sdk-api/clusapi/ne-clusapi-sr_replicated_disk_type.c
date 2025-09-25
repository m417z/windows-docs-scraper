typedef enum _SR_REPLICATED_DISK_TYPE {
  SrReplicatedDiskTypeNone = 0,
  SrReplicatedDiskTypeSource = 1,
  SrReplicatedDiskTypeLogSource = 2,
  SrReplicatedDiskTypeDestination = 3,
  SrReplicatedDiskTypeLogDestination = 4,
  SrReplicatedDiskTypeNotInParthership = 5,
  SrReplicatedDiskTypeLogNotInParthership = 6,
  SrReplicatedDiskTypeOther
} SR_REPLICATED_DISK_TYPE, *PSR_REPLICATED_DISK_TYPE;