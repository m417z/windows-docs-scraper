typedef struct _WHEAP_PROCESS_HEST_EVENT {
  WHEA_EVENT_LOG_ENTRY WheaEventLogEntry;
  CHAR                 Error[WHEA_ERROR_TEXT_LEN];
  CHAR                 EntryType[WHEA_ERROR_TEXT_LEN];
  ULONG                EntryIndex;
  BOOLEAN              HestValid;
  ULONG                CmcCount;
  ULONG                MceCount;
  ULONG                NmiCount;
  ULONG                AerRootCount;
  ULONG                AerBridgeCount;
  ULONG                AerEndPointCount;
  ULONG                GenericV1Count;
  ULONG                GenericV2Count;
} WHEAP_PROCESS_HEST_EVENT, *PWHEAP_PROCESS_HEST_EVENT;