typedef struct _DFS_INFO_5 {
  LPWSTR EntryPath;
  LPWSTR Comment;
  DWORD  State;
  ULONG  Timeout;
  GUID   Guid;
  ULONG  PropertyFlags;
  ULONG  MetadataSize;
  DWORD  NumberOfStorages;
} DFS_INFO_5, *PDFS_INFO_5, *LPDFS_INFO_5;