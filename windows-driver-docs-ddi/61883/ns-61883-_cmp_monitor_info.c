typedef struct _CMP_MONITOR_INFO {
  ULONG  State;
  ULONG  PlugNum;
  ULONG  PlugType;
  AV_PCR Pcr;
  PVOID  Context;
} CMP_MONITOR_INFO, *PCMP_MONITOR_INFO;