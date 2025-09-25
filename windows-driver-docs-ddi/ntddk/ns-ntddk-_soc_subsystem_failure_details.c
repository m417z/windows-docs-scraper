typedef struct _SOC_SUBSYSTEM_FAILURE_DETAILS {
  SOC_SUBSYSTEM_TYPE SubsysType;
  ULONG64            FirmwareVersion;
  ULONG64            HardwareVersion;
  ULONG              UnifiedFailureRegionSize;
  CHAR               UnifiedFailureRegion[1];
} SOC_SUBSYSTEM_FAILURE_DETAILS, *PSOC_SUBSYSTEM_FAILURE_DETAILS;