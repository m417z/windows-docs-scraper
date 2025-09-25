typedef union _WHEA_EVENT_LOG_ENTRY_FLAGS {
  struct {
    ULONG Reserved1 : 1;
    ULONG LogInternalEtw : 1;
    ULONG LogBlackbox : 1;
    ULONG LogSel : 1;
    ULONG RawSel : 1;
    ULONG NoFormat : 1;
    ULONG Driver : 1;
    ULONG Reserved2 : 25;
  } DUMMYSTRUCTNAME;
  ULONG  AsULONG;
} WHEA_EVENT_LOG_ENTRY_FLAGS, *PWHEA_EVENT_LOG_ENTRY_FLAGS;