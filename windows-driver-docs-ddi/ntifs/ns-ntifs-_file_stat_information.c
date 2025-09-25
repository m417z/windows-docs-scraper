typedef struct _FILE_STAT_INFORMATION {
  LARGE_INTEGER FileId;
  LARGE_INTEGER CreationTime;
  LARGE_INTEGER LastAccessTime;
  LARGE_INTEGER LastWriteTime;
  LARGE_INTEGER ChangeTime;
  LARGE_INTEGER AllocationSize;
  LARGE_INTEGER EndOfFile;
  ULONG         FileAttributes;
  ULONG         ReparseTag;
  ULONG         NumberOfLinks;
  ACCESS_MASK   EffectiveAccess;
} FILE_STAT_INFORMATION, *PFILE_STAT_INFORMATION;