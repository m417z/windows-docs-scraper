void NET_ADAPTER_OFFLOAD_GSO_CAPABILITIES_INIT(
  [_Out_] NET_ADAPTER_OFFLOAD_GSO_CAPABILITIES *GsoCapabilities,
  [_In_]  NET_ADAPTER_OFFLOAD_LAYER3_FLAGS     Layer3Flags,
  [_In_]  NET_ADAPTER_OFFLOAD_LAYER4_FLAGS     Layer4Flags,
  [_In_]  SIZE_T                               MaximumOffloadSize,
  [_In_]  SIZE_T                               MinimumSegmentCount,
  [_In_]  PFN_NET_ADAPTER_OFFLOAD_SET_GSO      EvtAdapterOffloadSetGso
);