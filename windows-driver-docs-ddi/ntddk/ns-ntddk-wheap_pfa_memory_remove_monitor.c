typedef struct _WHEAP_PFA_MEMORY_REMOVE_MONITOR {
  WHEA_EVENT_LOG_ENTRY    WheaEventLogEntry;
  WHEA_PFA_REMOVE_TRIGGER RemoveTrigger;
  ULONG                   TimeInList;
  ULONG                   ErrorCount;
  ULONG                   Page;
} WHEAP_PFA_MEMORY_REMOVE_MONITOR, *PWHEAP_PFA_MEMORY_REMOVE_MONITOR;