typedef struct _FILE_ID_EXTD_DIR_INFO {
  ULONG         NextEntryOffset;
  ULONG         FileIndex;
  LARGE_INTEGER CreationTime;
  LARGE_INTEGER LastAccessTime;
  LARGE_INTEGER LastWriteTime;
  LARGE_INTEGER ChangeTime;
  LARGE_INTEGER EndOfFile;
  LARGE_INTEGER AllocationSize;
  ULONG         FileAttributes;
  ULONG         FileNameLength;
  ULONG         EaSize;
  ULONG         ReparsePointTag;
  FILE_ID_128   FileId;
  WCHAR         FileName[1];
} FILE_ID_EXTD_DIR_INFO, *PFILE_ID_EXTD_DIR_INFO;