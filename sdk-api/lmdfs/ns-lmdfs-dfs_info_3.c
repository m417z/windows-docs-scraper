typedef struct _DFS_INFO_3 {
  LPWSTR             EntryPath;
  LPWSTR             Comment;
  DWORD              State;
  DWORD              NumberOfStorages;
#if ...
  LPDFS_STORAGE_INFO Storage;
#else
  LPDFS_STORAGE_INFO Storage;
#endif
} DFS_INFO_3, *PDFS_INFO_3, *LPDFS_INFO_3;