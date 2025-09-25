typedef struct _USBDEVICE_UPDATE_20_HARDWARE_LPM_PARAMETERS {
  ULONG HardwareLpmEnable : 1;
  ULONG RemoteWakeEnable : 1;
  ULONG HostInitiatedResumeDurationMode : 1;
  ULONG BestEffortServiceLatency : 4;
  ULONG BestEffortServiceLatencyDeep : 4;
  ULONG L1Timeout : 8;
  ULONG Reserved : 13;
} USBDEVICE_UPDATE_20_HARDWARE_LPM_PARAMETERS;