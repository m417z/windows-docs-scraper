typedef struct _FILE_QUERY_ON_DISK_VOL_INFO_BUFFER {
  LARGE_INTEGER DirectoryCount;
  LARGE_INTEGER FileCount;
  WORD          FsFormatMajVersion;
  WORD          FsFormatMinVersion;
  WCHAR         FsFormatName[12];
  LARGE_INTEGER FormatTime;
  LARGE_INTEGER LastUpdateTime;
  WCHAR         CopyrightInfo[34];
  WCHAR         AbstractInfo[34];
  WCHAR         FormattingImplementationInfo[34];
  WCHAR         LastModifyingImplementationInfo[34];
} FILE_QUERY_ON_DISK_VOL_INFO_BUFFER, *PFILE_QUERY_ON_DISK_VOL_INFO_BUFFER;