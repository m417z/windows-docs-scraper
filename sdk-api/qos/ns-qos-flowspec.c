typedef struct _flowspec {
  ULONG       TokenRate;
  ULONG       TokenBucketSize;
  ULONG       PeakBandwidth;
  ULONG       Latency;
  ULONG       DelayVariation;
  SERVICETYPE ServiceType;
  ULONG       MaxSduSize;
  ULONG       MinimumPolicedSize;
} FLOWSPEC, *PFLOWSPEC, *LPFLOWSPEC;