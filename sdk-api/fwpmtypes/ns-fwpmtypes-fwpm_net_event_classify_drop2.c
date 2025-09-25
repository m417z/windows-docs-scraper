typedef struct FWPM_NET_EVENT_CLASSIFY_DROP2_ {
  UINT64        filterId;
  UINT16        layerId;
  UINT32        reauthReason;
  UINT32        originalProfile;
  UINT32        currentProfile;
  UINT32        msFwpDirection;
  BOOL          isLoopback;
  FWP_BYTE_BLOB vSwitchId;
  UINT32        vSwitchSourcePort;
  UINT32        vSwitchDestinationPort;
} FWPM_NET_EVENT_CLASSIFY_DROP2;