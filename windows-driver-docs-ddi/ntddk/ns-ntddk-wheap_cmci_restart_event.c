typedef struct _WHEAP_CMCI_RESTART_EVENT {
  WHEA_EVENT_LOG_ENTRY WheaEventLogEntry;
  ULONG                CmciRestoreAttempts;
  ULONG                MaxCmciRestoreLimit;
  ULONG                MaxCorrectedErrorsFound;
  ULONG                MaxCorrectedErrorLimit;
} WHEAP_CMCI_RESTART_EVENT, *PWHEAP_CMCI_RESTART_EVENT;