typedef struct _NV_FEATURE_PARAMETER {
  USHORT NVPowerModeEnabled;
  USHORT NVParameterReserv1;
  USHORT NVCmdEnabled;
  USHORT NVParameterReserv2;
  USHORT NVPowerModeVer;
  USHORT NVCmdVer;
  ULONG  NVSize;
  USHORT NVReadSpeed;
  USHORT NVWrtSpeed;
  ULONG  DeviceSpinUpTime;
} NV_FEATURE_PARAMETER, *PNV_FEATURE_PARAMETER;