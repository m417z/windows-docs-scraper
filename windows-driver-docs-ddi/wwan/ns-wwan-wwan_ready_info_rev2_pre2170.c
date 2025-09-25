typedef struct _WWAN_READY_INFO_REV2_PRE2170 {
  WWAN_READY_STATE    ReadyState;
  WWAN_EMERGENCY_MODE EmergencyMode;
  WCHAR               SubscriberId[WWAN_SUBSCRIBERID_LEN];
  WCHAR               SimIccId[WWAN_SIMICCID_LEN];
  BYTE                CdmaShortMsgSize;
  ULONG               StatusFlags;
  WWAN_LIST_HEADER    TNListHeader;
} WWAN_READY_INFO_REV2_PRE2170, *PWWAN_READY_INFO_PRE2170;