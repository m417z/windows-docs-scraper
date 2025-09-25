typedef struct _TRACE_GUID_PROPERTIES {
  GUID    Guid;
  ULONG   GuidType;
  ULONG   LoggerId;
  ULONG   EnableLevel;
  ULONG   EnableFlags;
  BOOLEAN IsEnable;
} TRACE_GUID_PROPERTIES, *PTRACE_GUID_PROPERTIES;