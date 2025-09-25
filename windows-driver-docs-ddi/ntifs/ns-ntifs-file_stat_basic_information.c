typedef struct _FILE_STAT_BASIC_INFORMATION {
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
  ULONG         DeviceType;
  ULONG         DeviceCharacteristics;
  ULONG         Reserved;
  LARGE_INTEGER VolumeSerialNumber;
  FILE_ID_128   FileId128;
} FILE_STAT_BASIC_INFORMATION, *PFILE_STAT_BASIC_INFORMATION;