typedef struct _WHEAP_ATTEMPT_RECOVERY_EVENT {
  WHEA_EVENT_LOG_ENTRY     WheaEventLogEntry;
  WHEA_ERROR_RECORD_HEADER ErrorHeader;
  BOOLEAN                  ArchitecturalRecovery;
  BOOLEAN                  PshedRecovery;
  NTSTATUS                 Status;
} WHEAP_ATTEMPT_RECOVERY_EVENT, *PWHEAP_ATTEMPT_RECOVERY_EVENT;