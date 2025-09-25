typedef struct _FILE_STREAM_INFO {
  DWORD         NextEntryOffset;
  DWORD         StreamNameLength;
  LARGE_INTEGER StreamSize;
  LARGE_INTEGER StreamAllocationSize;
  WCHAR         StreamName[1];
} FILE_STREAM_INFO, *PFILE_STREAM_INFO;