typedef struct _DFS_STORAGE_INFO_1 {
  ULONG               State;
  LPWSTR              ServerName;
  LPWSTR              ShareName;
  DFS_TARGET_PRIORITY TargetPriority;
} DFS_STORAGE_INFO_1, *PDFS_STORAGE_INFO_1, *LPDFS_STORAGE_INFO_1;