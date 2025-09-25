typedef struct _USBDEVICE_UPDATE_FLAGS {
  ULONG UpdateDeviceDescriptor : 1;
  ULONG UpdateBosDescriptor : 1;
  ULONG UpdateMaxExitLatency : 1;
  ULONG UpdateIsHub : 1;
  ULONG UpdateAllowIoOnInvalidPipeHandles : 1;
  ULONG Update20HardwareLpmParameters : 1;
  ULONG UpdateRootPortResumeTime : 1;
  ULONG UpdateTunnelState : 1;
  ULONG Reserved : 25;
} USBDEVICE_UPDATE_FLAGS;