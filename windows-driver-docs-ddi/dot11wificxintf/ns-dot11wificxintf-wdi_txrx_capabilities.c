typedef struct _WDI_TXRX_TARGET_CAPABILITIES {
  WDI_INTERCONNECT_TYPE InterconnectType;
  struct {
    BOOLEAN TargetPriorityQueueing;
    UINT16  MaxScatterGatherElementsPerFrame;
    BOOLEAN ExplicitSendCompleteFlagRequired;
    UINT8   bPad;
    UINT16  MinEffectiveSize;
    UINT16  FrameSizeGranularity;
  } TransmitCapabilities;
  struct {
    BOOLEAN RxTxForwarding;
    UINT32  MaxThroughput;
  } ReceiveCapabilities;
} WDI_TXRX_CAPABILITIES, *PWDI_TXRX_CAPABILITIES;