typedef struct _WHEA_SEL_BUGCHECK_PROGRESS {
  WHEA_EVENT_LOG_ENTRY WheaEventLogEntry;
  ULONG                BugCheckCode;
  ULONG                BugCheckProgressSummary;
} WHEA_SEL_BUGCHECK_PROGRESS, *PWHEA_SEL_BUGCHECK_PROGRESS;