typedef struct _WHEAP_PFA_MEMORY_POLICY {
  WHEA_EVENT_LOG_ENTRY WheaEventLogEntry;
  ULONG                RegistryKeysPresent;
  BOOLEAN              DisableOffline;
  BOOLEAN              PersistOffline;
  BOOLEAN              PfaDisabled;
  ULONG                PageCount;
  ULONG                ErrorThreshold;
  ULONG                TimeOut;
} WHEAP_PFA_MEMORY_POLICY, *PWHEAP_PFA_MEMORY_POLICY;