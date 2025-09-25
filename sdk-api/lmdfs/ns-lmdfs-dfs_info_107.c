typedef struct _DFS_INFO_107 {
  LPWSTR               Comment;
  DWORD                State;
  ULONG                Timeout;
  ULONG                PropertyFlagMask;
  ULONG                PropertyFlags;
  ULONG                SecurityDescriptorLength;
#if ...
  PUCHAR               pSecurityDescriptor;
  ULONG                SdLengthReserved;
#else
  PSECURITY_DESCRIPTOR pSecurityDescriptor;
#endif
} DFS_INFO_107, *PDFS_INFO_107, *LPDFS_INFO_107;