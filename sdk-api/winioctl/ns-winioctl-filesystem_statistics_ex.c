typedef struct _FILESYSTEM_STATISTICS_EX {
  WORD      FileSystemType;
  WORD      Version;
  DWORD     SizeOfCompleteStructure;
  DWORDLONG UserFileReads;
  DWORDLONG UserFileReadBytes;
  DWORDLONG UserDiskReads;
  DWORDLONG UserFileWrites;
  DWORDLONG UserFileWriteBytes;
  DWORDLONG UserDiskWrites;
  DWORDLONG MetaDataReads;
  DWORDLONG MetaDataReadBytes;
  DWORDLONG MetaDataDiskReads;
  DWORDLONG MetaDataWrites;
  DWORDLONG MetaDataWriteBytes;
  DWORDLONG MetaDataDiskWrites;
} FILESYSTEM_STATISTICS_EX, *PFILESYSTEM_STATISTICS_EX;