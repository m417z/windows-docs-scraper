typedef struct _WHEAP_PSHED_PLUGIN_REGISTER {
  WHEA_EVENT_LOG_ENTRY WheaEventLogEntry;
  ULONG                Version;
  ULONG                Length;
  ULONG                FunctionalAreaMask;
  NTSTATUS             Status;
} WHEAP_PSHED_PLUGIN_REGISTER, *PWHEAP_PSHED_PLUGIN_REGISTER;