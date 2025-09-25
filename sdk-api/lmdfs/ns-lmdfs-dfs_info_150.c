typedef struct _DFS_INFO_150 {
  ULONG                SecurityDescriptorLength;
#if ...
  PUCHAR               pSecurityDescriptor;
  ULONG                SdLengthReserved;
#else
  PSECURITY_DESCRIPTOR pSecurityDescriptor;
#endif
} DFS_INFO_150, *PDFS_INFO_150, *LPDFS_INFO_150;