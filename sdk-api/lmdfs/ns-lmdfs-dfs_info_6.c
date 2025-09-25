typedef struct _DFS_INFO_6 {
  LPWSTR               EntryPath;
  LPWSTR               Comment;
  DWORD                State;
  ULONG                Timeout;
  GUID                 Guid;
  ULONG                PropertyFlags;
  ULONG                MetadataSize;
  DWORD                NumberOfStorages;
#if ...
  LPDFS_STORAGE_INFO_1 Storage;
#else
  LPDFS_STORAGE_INFO_1 Storage;
#endif
} DFS_INFO_6, *PDFS_INFO_6, *LPDFS_INFO_6;