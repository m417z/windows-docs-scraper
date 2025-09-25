typedef struct _WHEA_SRAS_TABLE_ENTRIES_EVENT {
  WHEA_EVENT_LOG_ENTRY WheaEventLogEntry;
  UINT32               LogNumber;
  UINT32               NumberSignals;
  UINT8                Data[ANY_SIZE];
} WHEA_SRAS_TABLE_ENTRIES_EVENT, *PWHEA_SRAS_TABLE_ENTRIES_EVENT;