typedef struct _HTTP_FLOWRATE_INFO {
  HTTP_PROPERTY_FLAGS Flags;
  ULONG               MaxBandwidth;
  ULONG               MaxPeakBandwidth;
  ULONG               BurstSize;
} HTTP_FLOWRATE_INFO, *PHTTP_FLOWRATE_INFO;