typedef struct _ENDPOINTS_CONFIGURE_FAILURE_FLAGS {
  ULONG InsufficientBandwidth : 1;
  ULONG InsufficientHardwareResourcesForEndpoints : 1;
  ULONG MaxExitLatencyTooLarge : 1;
  ULONG Reserved : 29;
} ENDPOINTS_CONFIGURE_FAILURE_FLAGS;