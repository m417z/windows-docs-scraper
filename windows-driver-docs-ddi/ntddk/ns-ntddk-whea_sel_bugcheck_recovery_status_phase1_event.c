typedef struct _WHEA_SEL_BUGCHECK_RECOVERY_STATUS_PHASE1_EVENT {
  WHEA_EVENT_LOG_ENTRY WheaEventLogEntry;
  BOOLEAN              Success;
  UCHAR                Version;
  USHORT               EntryCount;
  struct {
    UCHAR DumpPolicy;
    UCHAR Reserved[3];
  } Data;
} WHEA_SEL_BUGCHECK_RECOVERY_STATUS_PHASE1_EVENT, *PWHEA_SEL_BUGCHECK_RECOVERY_STATUS_PHASE1_EVENT;