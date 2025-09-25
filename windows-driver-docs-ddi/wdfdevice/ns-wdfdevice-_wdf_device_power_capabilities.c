typedef struct _WDF_DEVICE_POWER_CAPABILITIES {
  ULONG              Size;
  WDF_TRI_STATE      DeviceD1;
  WDF_TRI_STATE      DeviceD2;
  WDF_TRI_STATE      WakeFromD0;
  WDF_TRI_STATE      WakeFromD1;
  WDF_TRI_STATE      WakeFromD2;
  WDF_TRI_STATE      WakeFromD3;
  DEVICE_POWER_STATE DeviceState[PowerSystemMaximum];
  DEVICE_POWER_STATE DeviceWake;
  SYSTEM_POWER_STATE SystemWake;
  ULONG              D1Latency;
  ULONG              D2Latency;
  ULONG              D3Latency;
  DEVICE_POWER_STATE IdealDxStateForSx;
} WDF_DEVICE_POWER_CAPABILITIES, *PWDF_DEVICE_POWER_CAPABILITIES;