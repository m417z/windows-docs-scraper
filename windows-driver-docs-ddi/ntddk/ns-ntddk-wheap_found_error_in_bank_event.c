typedef struct _WHEAP_FOUND_ERROR_IN_BANK_EVENT {
  WHEA_EVENT_LOG_ENTRY WheaEventLogEntry;
  ULONG                EpIndex;
  ULONG                Bank;
  ULONG64              MciStatus;
  ULONG                ErrorType;
} WHEAP_FOUND_ERROR_IN_BANK_EVENT, *PWHEAP_FOUND_ERROR_IN_BANK_EVENT;