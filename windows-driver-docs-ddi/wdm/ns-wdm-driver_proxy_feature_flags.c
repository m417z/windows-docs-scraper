typedef union _DRIVER_PROXY_FEATURE_FLAGS {
  ULONG  AsUlong;
  struct {
    ULONG Enabled : 1;
    ULONG Reserved : 31;
  };
} DRIVER_PROXY_FEATURE_FLAGS, *PDRIVER_PROXY_FEATURE_FLAGS;