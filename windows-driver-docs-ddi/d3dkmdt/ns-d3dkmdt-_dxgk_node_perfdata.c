typedef struct _DXGK_NODE_PERFDATA {
  ULONGLONG Frequency;
  ULONGLONG MaxFrequency;
  ULONGLONG MaxFrequencyOC;
  ULONG     Voltage;
  ULONG     VoltageMax;
  ULONG     VoltageMaxOC;
  ULONGLONG MaxTransitionLatency;
} DXGK_NODE_PERFDATA;