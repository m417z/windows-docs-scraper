NTSTATUS AcxPinAddStreamBridges(
  [in]                            ACXPIN          Pin,
  [in, reads(StreamBridgesCount)] ACXSTREAMBRIDGE *StreamBridges,
  [in]                            ULONG           StreamBridgesCount
);