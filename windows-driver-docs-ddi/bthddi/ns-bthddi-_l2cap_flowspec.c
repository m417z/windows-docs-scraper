typedef struct _L2CAP_FLOWSPEC {
  UCHAR Flags;
  UCHAR ServiceType;
  ULONG TokenRate;
  ULONG TokenBucketSize;
  ULONG PeakBandwidth;
  ULONG Latency;
  ULONG DelayVariation;
} L2CAP_FLOWSPEC, *PL2CAP_FLOWSPEC;