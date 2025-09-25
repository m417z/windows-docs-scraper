void NET_ADAPTER_OFFLOAD_CHECKSUM_CAPABILITIES_INIT(
  [_Out_] NET_ADAPTER_OFFLOAD_CHECKSUM_CAPABILITIES *ChecksumCapabilities,
  [_In_]  BOOLEAN                                   IPv4,
  [_In_]  BOOLEAN                                   Tcp,
  [_In_]  BOOLEAN                                   Udp,
  [_In_]  PFN_NET_ADAPTER_OFFLOAD_SET_CHECKSUM      EvtAdapterOffloadSetChecksum
);