typedef struct _WHEAP_ERR_SRC_ARRAY_INVALID_EVENT {
  WHEA_EVENT_LOG_ENTRY WheaEventLogEntry;
  ULONG                ErrorSourceCount;
  ULONG                ReportedLength;
  ULONG                ExpectedLength;
} WHEAP_ERR_SRC_ARRAY_INVALID_EVENT, *PWHEAP_ERR_SRC_ARRAY_INVALID_EVENT;