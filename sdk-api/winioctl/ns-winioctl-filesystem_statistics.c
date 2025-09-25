typedef struct _FILESYSTEM_STATISTICS {
  WORD  FileSystemType;
  WORD  Version;
  DWORD SizeOfCompleteStructure;
  DWORD UserFileReads;
  DWORD UserFileReadBytes;
  DWORD UserDiskReads;
  DWORD UserFileWrites;
  DWORD UserFileWriteBytes;
  DWORD UserDiskWrites;
  DWORD MetaDataReads;
  DWORD MetaDataReadBytes;
  DWORD MetaDataDiskReads;
  DWORD MetaDataWrites;
  DWORD MetaDataWriteBytes;
  DWORD MetaDataDiskWrites;
} FILESYSTEM_STATISTICS, *PFILESYSTEM_STATISTICS;