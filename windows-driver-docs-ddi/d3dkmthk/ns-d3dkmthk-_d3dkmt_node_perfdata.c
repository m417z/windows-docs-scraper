typedef struct _D3DKMT_NODE_PERFDATA {
  [in]  UINT32                   NodeOrdinal;
  [in]  UINT32                   PhysicalAdapterIndex;
  [out] D3DKMT_ALIGN64 ULONGLONG Frequency;
  [out] D3DKMT_ALIGN64 ULONGLONG MaxFrequency;
  [out] D3DKMT_ALIGN64 ULONGLONG MaxFrequencyOC;
  [out] ULONG                    Voltage;
  [out] ULONG                    VoltageMax;
  [out] ULONG                    VoltageMaxOC;
  [out] D3DKMT_ALIGN64 ULONGLONG MaxTransitionLatency;
        D3DKMT_ALIGN64 ULONGLONG Reserved;
} D3DKMT_NODE_PERFDATA;