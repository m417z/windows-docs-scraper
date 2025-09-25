typedef enum _SR_DISK_REPLICATION_ELIGIBLE {
  SrDiskReplicationEligibleNone = 0,
  SrDiskReplicationEligibleYes = 1,
  SrDiskReplicationEligibleOffline = 2,
  SrDiskReplicationEligibleNotGpt = 3,
  SrDiskReplicationEligiblePartitionLayoutMismatch = 4,
  SrDiskReplicationEligibleInsufficientFreeSpace = 5,
  SrDiskReplicationEligibleNotInSameSite = 6,
  SrDiskReplicationEligibleInSameSite = 7,
  SrDiskReplicationEligibleFileSystemNotSupported = 8,
  SrDiskReplicationEligibleAlreadyInReplication = 9,
  SrDiskReplicationEligibleSameAsSpecifiedDisk = 10,
  SrDiskReplicationEligibleOther = 9999
} SR_DISK_REPLICATION_ELIGIBLE, *PSR_DISK_REPLICATION_ELIGIBLE;