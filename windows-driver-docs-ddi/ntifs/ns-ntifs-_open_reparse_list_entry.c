typedef struct _OPEN_REPARSE_LIST_ENTRY {
  LIST_ENTRY OpenReparseListEntry;
  ULONG      ReparseTag;
  ULONG      Flags;
  GUID       ReparseGuid;
  USHORT     Size;
  USHORT     RemainingLength;
} OPEN_REPARSE_LIST_ENTRY, *POPEN_REPARSE_LIST_ENTRY;