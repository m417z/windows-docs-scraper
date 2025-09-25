typedef struct _DXGK_ADAPTER_PERFDATA {
  ULONGLONG MemoryFrequency;
  ULONGLONG MaxMemoryFrequency;
  ULONGLONG MaxMemoryFrequencyOC;
  ULONGLONG MemoryBandwidth;
  ULONGLONG PCIEBandwidth;
  ULONG     FanRPM;
  ULONG     Power;
  ULONG     Temperature;
  UCHAR     PowerStateOverride;
} DXGK_ADAPTER_PERFDATA;