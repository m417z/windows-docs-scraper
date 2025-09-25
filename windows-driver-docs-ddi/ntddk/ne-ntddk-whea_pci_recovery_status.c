typedef enum _WHEA_PCI_RECOVERY_STATUS {
  WheaPciREcoveryStatusUnknown,
  WheaPciRecoveryStatusNoError,
  WheaPciRecoveryStatusLinkDisableTimeout,
  WheaPciRecoveryStatusLinkEnableTimeout,
  WheaPciRecoveryStatusRpBusyTimeout,
  WheaPciRecoveryStatusComplexTree,
  WheaPciRecoveryStatusBusNotFound,
  WheaPciRecoveryStatusDeviceNotFound,
  WheaPciRecoveryStatusDdaAerNotRecoverable,
  WheaPciRecoveryStatusFailedRecovery
} WHEA_PCI_RECOVERY_STATUS, *PWHEA_PCI_RECOVERY_STATUS;