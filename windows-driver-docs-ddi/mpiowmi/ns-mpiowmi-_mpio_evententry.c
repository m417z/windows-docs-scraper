typedef struct _MPIO_EventEntry {
  ULONGLONG TimeStamp;
  ULONG     Severity;
  WCHAR     Component[63 + 1];
  WCHAR     EventDescription[63 + 1];
} MPIO_EventEntry, *PMPIO_EventEntry;