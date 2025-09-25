typedef struct _WWAN_READY_INFO_REV1 {
  WWAN_READY_STATE    ReadyState;
  WWAN_EMERGENCY_MODE EmergencyMode;
  WCHAR               SubscriberId[WWAN_SUBSCRIBERID_LEN];
  WCHAR               SimIccId[WWAN_SIMICCID_LEN];
  BYTE                CdmaShortMsgSize;
  WWAN_LIST_HEADER    TNListHeader;
} WWAN_READY_INFO_REV1, *PWWAN_READY_INFO_REV1;