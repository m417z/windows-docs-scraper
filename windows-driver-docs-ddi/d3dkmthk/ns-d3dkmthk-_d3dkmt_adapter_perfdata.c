typedef struct _D3DKMT_ADAPTER_PERFDATA {
  UINT32                   PhysicalAdapterIndex;
  D3DKMT_ALIGN64 ULONGLONG MemoryFrequency;
  D3DKMT_ALIGN64 ULONGLONG MaxMemoryFrequency;
  D3DKMT_ALIGN64 ULONGLONG MaxMemoryFrequencyOC;
  D3DKMT_ALIGN64 ULONGLONG MemoryBandwidth;
  D3DKMT_ALIGN64 ULONGLONG PCIEBandwidth;
  ULONG                    FanRPM;
  ULONG                    Power;
  ULONG                    Temperature;
  UCHAR                    PowerStateOverride;
} D3DKMT_ADAPTER_PERFDATA;