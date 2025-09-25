typedef struct _DFS_INFO_4 {
  LPWSTR             EntryPath;
  LPWSTR             Comment;
  DWORD              State;
  ULONG              Timeout;
  GUID               Guid;
  DWORD              NumberOfStorages;
#if ...
  LPDFS_STORAGE_INFO Storage;
#else
  LPDFS_STORAGE_INFO Storage;
#endif
} DFS_INFO_4, *PDFS_INFO_4, *LPDFS_INFO_4;