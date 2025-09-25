typedef struct _FILE_NOTIFY_EXTENDED_INFORMATION {
  DWORD         NextEntryOffset;
  DWORD         Action;
  LARGE_INTEGER CreationTime;
  LARGE_INTEGER LastModificationTime;
  LARGE_INTEGER LastChangeTime;
  LARGE_INTEGER LastAccessTime;
  LARGE_INTEGER AllocatedLength;
  LARGE_INTEGER FileSize;
  DWORD         FileAttributes;
  union {
    DWORD ReparsePointTag;
    DWORD EaSize;
  } DUMMYUNIONNAME;
  LARGE_INTEGER FileId;
  LARGE_INTEGER ParentFileId;
  DWORD         FileNameLength;
  WCHAR         FileName[1];
} FILE_NOTIFY_EXTENDED_INFORMATION, *PFILE_NOTIFY_EXTENDED_INFORMATION;