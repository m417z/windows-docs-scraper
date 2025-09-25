typedef struct _PEP_PLATFORM_IDLE_STATE {
  POHANDLE                      InitiatingProcessor;
  UCHAR                         InitiatingState;
  ULONG                         Latency;
  ULONG                         BreakEvenDuration;
  ULONG                         DependencyArrayUsed;
  ULONG                         DependencyArrayCount;
  PEP_PROCESSOR_IDLE_DEPENDENCY DependencyArray[ANYSIZE_ARRAY];
} PEP_PLATFORM_IDLE_STATE, *PPEP_PLATFORM_IDLE_STATE;