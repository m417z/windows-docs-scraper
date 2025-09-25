typedef struct _WHEAP_ROW_FAILURE_EVENT {
  WHEA_EVENT_LOG_ENTRY WheaEventLogEntry;
  PFN_NUMBER           LowOrderPage;
  PFN_NUMBER           HighOrderPage;
} WHEAP_ROW_FAILURE_EVENT, *PWHEAP_ROW_FAILURE_EVENT;