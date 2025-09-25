typedef struct _REASON_CONTEXT {
  ULONG Version;
  DWORD Flags;
  union {
    struct {
      HMODULE LocalizedReasonModule;
      ULONG   LocalizedReasonId;
      ULONG   ReasonStringCount;
      LPWSTR  *ReasonStrings;
    } Detailed;
    LPWSTR SimpleReasonString;
  } Reason;
} REASON_CONTEXT, *PREASON_CONTEXT;