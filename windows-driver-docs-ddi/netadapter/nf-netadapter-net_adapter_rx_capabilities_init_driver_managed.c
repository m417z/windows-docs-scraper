void NET_ADAPTER_RX_CAPABILITIES_INIT_DRIVER_MANAGED(
  [_Out_] NET_ADAPTER_RX_CAPABILITIES      *RxCapabilities,
  [_In_]  PFN_NET_ADAPTER_RETURN_RX_BUFFER EvtAdapterReturnRxBuffer,
  [_In_]  SIZE_T                           MaximumFrameSize,
  [_In_]  SIZE_T                           MaximumNumberOfQueues
);