typedef struct _CIMFS_FILE_METADATA {
  UINT32        Attributes;
  INT64         FileSize;
  LARGE_INTEGER CreationTime;
  LARGE_INTEGER LastWriteTime;
  LARGE_INTEGER ChangeTime;
  LARGE_INTEGER LastAccessTime;
  const void    *SecurityDescriptorBuffer;
  UINT32        SecurityDescriptorSize;
  const void    *ReparseDataBuffer;
  UINT32        ReparseDataSize;
  const void    *EaBuffer;
  UINT32        EaBufferSize;
} CIMFS_FILE_METADATA;