typedef struct {
  USHORT DfsEntryPathLen;
  USHORT ServerNameLen;
  USHORT ShareNameLen;
  ULONG  Level;
  WCHAR  Buffer[1];
} DFS_GET_PKT_ENTRY_STATE_ARG, *PDFS_GET_PKT_ENTRY_STATE_ARG;