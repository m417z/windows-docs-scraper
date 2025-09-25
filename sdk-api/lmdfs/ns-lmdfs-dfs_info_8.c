typedef struct _DFS_INFO_8 {
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
} DFS_INFO_8, *PDFS_INFO_8, *LPDFS_INFO_8;