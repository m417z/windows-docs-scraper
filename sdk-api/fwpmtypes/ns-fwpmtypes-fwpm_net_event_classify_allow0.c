typedef struct FWPM_NET_EVENT_CLASSIFY_ALLOW0 {
  UINT64 filterId;
  UINT16 layerId;
  UINT32 reauthReason;
  UINT32 originalProfile;
  UINT32 currentProfile;
  UINT32 msFwpDirection;
  BOOL   isLoopback;
} FWPM_NET_EVENT_CLASSIFY_ALLOW0;