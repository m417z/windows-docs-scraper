typedef struct _WHEAP_GENERIC_ERR_MEM_MAP_EVENT {
  WHEA_EVENT_LOG_ENTRY WheaEventLogEntry;
  CHAR                 MapReason[WHEA_ERROR_TEXT_LEN];
  ULONG64              PhysicalAddress;
  ULONG64              Length;
} WHEAP_GENERIC_ERR_MEM_MAP_EVENT, *PWHEAP_GENERIC_ERR_MEM_MAP_EVENT;