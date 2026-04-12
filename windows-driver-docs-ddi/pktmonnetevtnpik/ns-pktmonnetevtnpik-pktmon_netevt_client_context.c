typedef struct _PKTMON_NETEVT_CLIENT_CONTEXT {
  HANDLE                          NmrClientHandle;
  PEX_RUNDOWN_REF_CACHE_AWARE     RundownRef;
  BOOLEAN                         Enabled;
  PVOID                           ProviderContext;
  PKTMON_NETEVT_PROVIDER_DISPATCH *ProviderDispatch;
} PKTMON_NETEVT_CLIENT_CONTEXT;