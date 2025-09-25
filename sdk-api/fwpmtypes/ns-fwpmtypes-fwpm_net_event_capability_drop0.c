typedef struct FWPM_NET_EVENT_CAPABILITY_DROP0_ {
  FWPM_APPC_NETWORK_CAPABILITY_TYPE networkCapabilityId;
  UINT64                            filterId;
  BOOL                              isLoopback;
} FWPM_NET_EVENT_CAPABILITY_DROP0;