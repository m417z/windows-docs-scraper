typedef struct _WHEAP_PSHED_INJECT_ERROR {
  WHEA_EVENT_LOG_ENTRY WheaEventLogEntry;
  ULONG                ErrorType;
  ULONGLONG            Parameter1;
  ULONGLONG            Parameter2;
  ULONGLONG            Parameter3;
  ULONGLONG            Parameter4;
  NTSTATUS             InjectionStatus;
  BOOLEAN              InjectionAttempted;
  BOOLEAN              InjectionByPlugin;
} WHEAP_PSHED_INJECT_ERROR, *PWHEAP_PSHED_INJECT_ERROR;