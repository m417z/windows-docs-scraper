typedef struct _DEBUG_BREAKPOINT_PARAMETERS {
  ULONG64 Offset;
  ULONG   Id;
  ULONG   BreakType;
  ULONG   ProcType;
  ULONG   Flags;
  ULONG   DataSize;
  ULONG   DataAccessType;
  ULONG   PassCount;
  ULONG   CurrentPassCount;
  ULONG   MatchThread;
  ULONG   CommandSize;
  ULONG   OffsetExpressionSize;
} DEBUG_BREAKPOINT_PARAMETERS, *PDEBUG_BREAKPOINT_PARAMETERS;