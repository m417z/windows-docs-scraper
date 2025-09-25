typedef struct _STOR_UC_DEVICE_USAGE {
  PSTOR_ADDRESS             Address;
  SCSI_UC_DEVICE_USAGE_TYPE UsageType;
  BOOLEAN                   InUse;
} STOR_UC_DEVICE_USAGE, *PSTOR_UC_DEVICE_USAGE;