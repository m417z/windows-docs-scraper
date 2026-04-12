typedef struct _PKTMON_NETEVT_CLIENT_DISPATCH_V2 {
  PKTMON_NETEVT_DISPATCH_HEADER Header;
  PKTMON_CAPTURE_TYPE           CaptureType;
  UINT32                        HandlerCount;
  UINT64                        *Handlers;
} PKTMON_NETEVT_CLIENT_DISPATCH_V2;