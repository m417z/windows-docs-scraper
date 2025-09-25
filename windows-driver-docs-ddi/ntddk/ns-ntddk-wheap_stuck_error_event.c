typedef struct _WHEAP_STUCK_ERROR_EVENT {
  WHEA_EVENT_LOG_ENTRY WheaEventLogEntry;
  ULONG                EpIndex;
  ULONG                Bank;
  ULONG64              MciStatus;
} WHEAP_STUCK_ERROR_EVENT, *PWHEAP_STUCK_ERROR_EVENT;