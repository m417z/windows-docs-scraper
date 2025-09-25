typedef union _UCX_CONTROLLER_TRANSPORT_CHARACTERISTICS_CHANGE_FLAGS {
  ULONG  AsUlong32;
  struct {
    ULONG CurrentRoundtripLatencyChanged : 1;
    ULONG CurrentTotalBandwidthChanged : 1;
  } Flags;
  struct {
    ULONG CurrentRoundtripLatencyChanged : 1;
    ULONG CurrentTotalBandwidthChanged : 1;
  };
} UCX_CONTROLLER_TRANSPORT_CHARACTERISTICS_CHANGE_FLAGS;