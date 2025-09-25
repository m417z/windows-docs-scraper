typedef struct _WHEAP_CMCI_INITERR_EVENT {
  WHEA_EVENT_LOG_ENTRY WheaEventLogEntry;
  ULONGLONG            Msr;
  ULONG                Type;
  ULONG                Bank;
  ULONG                EpIndex;
} WHEAP_CMCI_INITERR_EVENT, *PWHEAP_CMCI_INITERR_EVENT;