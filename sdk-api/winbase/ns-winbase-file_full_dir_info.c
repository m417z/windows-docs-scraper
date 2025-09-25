typedef struct _FILE_FULL_DIR_INFO {
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
  WCHAR         FileName[1];
} FILE_FULL_DIR_INFO, *PFILE_FULL_DIR_INFO;