typedef struct _PEP_COORDINATED_IDLE_STATE {
  ULONG Latency;
  ULONG BreakEvenDuration;
  ULONG DependencyCount;
  ULONG MaximumDependencySize;
} PEP_COORDINATED_IDLE_STATE, *PPEP_COORDINATED_IDLE_STATE;