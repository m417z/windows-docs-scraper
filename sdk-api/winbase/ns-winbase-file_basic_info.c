typedef struct _FILE_BASIC_INFO {
  LARGE_INTEGER CreationTime;
  LARGE_INTEGER LastAccessTime;
  LARGE_INTEGER LastWriteTime;
  LARGE_INTEGER ChangeTime;
  DWORD         FileAttributes;
} FILE_BASIC_INFO, *PFILE_BASIC_INFO;