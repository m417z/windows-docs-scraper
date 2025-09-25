void NET_ADAPTER_RX_CAPABILITIES_INIT_SYSTEM_MANAGED_DMA(
  [_Out_] NET_ADAPTER_RX_CAPABILITIES  *RxCapabilities,
  [_In_]  NET_ADAPTER_DMA_CAPABILITIES *DmaCapabilities,
  [_In_]  SIZE_T                       MaximumFrameSize,
  [_In_]  SIZE_T                       MaximumNumberOfQueues
);