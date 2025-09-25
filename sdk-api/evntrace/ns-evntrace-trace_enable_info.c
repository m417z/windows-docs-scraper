typedef struct _TRACE_ENABLE_INFO {
  ULONG     IsEnabled;
  UCHAR     Level;
  UCHAR     Reserved1;
  USHORT    LoggerId;
  ULONG     EnableProperty;
  ULONG     Reserved2;
  ULONGLONG MatchAnyKeyword;
  ULONGLONG MatchAllKeyword;
} TRACE_ENABLE_INFO, *PTRACE_ENABLE_INFO;