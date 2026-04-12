typedef struct _PKTMON_NETEVT_PROVIDER_DISPATCH {
  PKTMON_NETEVT_DISPATCH_HEADER Header;
  UINT32                        HandlerCount;
  UINT64                        *Handlers;
} PKTMON_NETEVT_PROVIDER_DISPATCH;