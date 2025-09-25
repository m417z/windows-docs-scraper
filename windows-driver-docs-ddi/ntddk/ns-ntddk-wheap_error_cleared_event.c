typedef struct _WHEAP_ERROR_CLEARED_EVENT {
  WHEA_EVENT_LOG_ENTRY WheaEventLogEntry;
  ULONG                EpIndex;
  ULONG                Bank;
} WHEAP_ERROR_CLEARED_EVENT, *PWHEAP_ERROR_CLEARED_EVENT;