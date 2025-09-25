typedef struct _PEP_PPM_QUERY_DOMAIN_INFO {
  ULONG   DomainId;
  UCHAR   CoordinationType;
  BOOLEAN IdleProcessorsDiscounted;
  BOOLEAN SchedulerDirectedTransitionsSupported;
  BOOLEAN AffinitizePerfSet;
  ULONG   WorstCaseTransitionLatency;
  ULONG   WorstCaseTransitionOverhead;
} PEP_PPM_QUERY_DOMAIN_INFO, *PPEP_PPM_QUERY_DOMAIN_INFO;