typedef struct _WHEAP_EDPC_ENABLED_EVENT {
  WHEA_EVENT_LOG_ENTRY WheaEventLogEntry;
  BOOLEAN              eDPCEnabled;
  BOOLEAN              eDPCRecovEnabled;
} WHEAP_EDPC_ENABLED_EVENT, *PWHEAP_EDPC_ENABLED_EVENT;