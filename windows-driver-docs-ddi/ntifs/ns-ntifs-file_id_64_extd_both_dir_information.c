typedef struct _FILE_ID_64_EXTD_BOTH_DIR_INFORMATION {
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
  LARGE_INTEGER FileId;
  CCHAR         ShortNameLength;
  WCHAR         ShortName[12];
  WCHAR         FileName[1];
} FILE_ID_64_EXTD_BOTH_DIR_INFORMATION, *PFILE_ID_64_EXTD_BOTH_DIR_INFORMATION;