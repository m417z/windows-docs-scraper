typedef struct _DXGK_ADAPTER_PERFDATACAPS {
  ULONGLONG MaxMemoryBandwidth;
  ULONGLONG MaxPCIEBandwidth;
  ULONG     MaxFanRPM;
  ULONG     TemperatureMax;
  ULONG     TemperatureWarning;
} DXGK_ADAPTER_PERFDATACAPS;