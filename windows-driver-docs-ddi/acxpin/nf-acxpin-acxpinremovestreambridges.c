NTSTATUS AcxPinRemoveStreamBridges(
  [in]                            ACXPIN          Pin,
  [in, reads(StreamBridgesCount)] ACXSTREAMBRIDGE *StreamBridges,
                                  ULONG           StreamBridgesCount
);