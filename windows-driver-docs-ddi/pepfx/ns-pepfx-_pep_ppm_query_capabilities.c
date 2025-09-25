typedef struct _PEP_PPM_QUERY_CAPABILITIES {
  ULONG   FeedbackCounterCount;
  ULONG   IdleStateCount;
  BOOLEAN PerformanceStatesSupported;
  BOOLEAN ParkingSupported;
  UCHAR   DiscretePerformanceStateCount;
  UCHAR   Reserved;
} PEP_PPM_QUERY_CAPABILITIES, *PPEP_PPM_QUERY_CAPABILITIES;