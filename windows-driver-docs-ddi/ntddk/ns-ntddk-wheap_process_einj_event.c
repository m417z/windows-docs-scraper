typedef struct _WHEAP_PROCESS_EINJ_EVENT {
  WHEA_EVENT_LOG_ENTRY WheaEventLogEntry;
  CHAR                 Error[WHEA_ERROR_TEXT_LEN];
  BOOLEAN              InjectionActionTableValid;
  ULONG                BeginInjectionInstructionCount;
  ULONG                GetTriggerErrorActionTableInstructionCount;
  ULONG                SetErrorTypeInstructionCount;
  ULONG                GetErrorTypeInstructionCount;
  ULONG                EndOperationInstructionCount;
  ULONG                ExecuteOperationInstructionCount;
  ULONG                CheckBusyStatusInstructionCount;
  ULONG                GetCommandStatusInstructionCount;
  ULONG                SetErrorTypeWithAddressInstructionCount;
  ULONG                GetExecuteOperationTimingsInstructionCount;
} WHEAP_PROCESS_EINJ_EVENT, *PWHEAP_PROCESS_EINJ_EVENT;