typedef union _PARENT_HUB_FLAGS {
  ULONG  AsUlong32;
  struct {
    ULONG DisableLpmForAllDownstreamDevices : 1;
    ULONG HubIsHighSpeedCapable : 1;
    ULONG DisableUpdateMaxExitLatency : 1;
    ULONG DisableU1 : 1;
  } Flags;
  struct {
    ULONG DisableLpmForAllDownstreamDevices : 1;
    ULONG HubIsHighSpeedCapable : 1;
    ULONG DisableUpdateMaxExitLatency : 1;
    ULONG DisableU1 : 1;
  };
} PARENT_HUB_FLAGS, *PPARENT_HUB_FLAGS;