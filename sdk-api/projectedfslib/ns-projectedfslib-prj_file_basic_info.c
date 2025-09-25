typedef struct PRJ_FILE_BASIC_INFO {
  BOOLEAN       IsDirectory;
  INT64         FileSize;
  LARGE_INTEGER CreationTime;
  LARGE_INTEGER LastAccessTime;
  LARGE_INTEGER LastWriteTime;
  LARGE_INTEGER ChangeTime;
  UINT32        FileAttributes;
} PRJ_FILE_BASIC_INFO;