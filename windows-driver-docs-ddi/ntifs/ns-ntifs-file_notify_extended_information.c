typedef struct _FILE_NOTIFY_EXTENDED_INFORMATION {
  ULONG         NextEntryOffset;
  ULONG         Action;
  LARGE_INTEGER CreationTime;
  LARGE_INTEGER LastModificationTime;
  LARGE_INTEGER LastChangeTime;
  LARGE_INTEGER LastAccessTime;
  LARGE_INTEGER AllocatedLength;
  LARGE_INTEGER FileSize;
  ULONG         FileAttributes;
  union {
    ULONG ReparsePointTag;
    ULONG EaSize;
  } DUMMYUNIONNAME;
  LARGE_INTEGER FileId;
  LARGE_INTEGER ParentFileId;
  ULONG         FileNameLength;
  WCHAR         FileName[1];
} FILE_NOTIFY_EXTENDED_INFORMATION, *PFILE_NOTIFY_EXTENDED_INFORMATION;