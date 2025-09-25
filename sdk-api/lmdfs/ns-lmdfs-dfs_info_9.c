typedef struct _DFS_INFO_9 {
  LPWSTR               EntryPath;
  LPWSTR               Comment;
  DWORD                State;
  ULONG                Timeout;
  GUID                 Guid;
  ULONG                PropertyFlags;
  ULONG                MetadataSize;
  ULONG                SecurityDescriptorLength;
#if ...
  PUCHAR               pSecurityDescriptor;
  ULONG                SdLengthReserved;
#else
  PSECURITY_DESCRIPTOR pSecurityDescriptor;
#endif
  DWORD                NumberOfStorages;
#if ...
  LPDFS_STORAGE_INFO_1 Storage;
#else
  LPDFS_STORAGE_INFO_1 Storage;
#endif
} DFS_INFO_9, *PDFS_INFO_9, *LPDFS_INFO_9;