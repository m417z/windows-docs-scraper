typedef struct _D3DKMT_ADAPTER_PERFDATACAPS {
  UINT32                   PhysicalAdapterIndex;
  D3DKMT_ALIGN64 ULONGLONG MaxMemoryBandwidth;
  D3DKMT_ALIGN64 ULONGLONG MaxPCIEBandwidth;
  ULONG                    MaxFanRPM;
  ULONG                    TemperatureMax;
  ULONG                    TemperatureWarning;
} D3DKMT_ADAPTER_PERFDATACAPS;