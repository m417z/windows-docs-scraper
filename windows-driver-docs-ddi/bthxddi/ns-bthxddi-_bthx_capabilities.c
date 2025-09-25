typedef struct _BTHX_CAPABILITIES {
  ULONG            MaxAclTransferInSize;
  BTHX_SCO_SUPPORT ScoSupport;
  ULONG            MaxScoChannels;
  BOOLEAN          IsDeviceIdleCapable;
  BOOLEAN          IsDeviceWakeCapable;
} BTHX_CAPABILITIES, *PBTHX_CAPABILITIES;