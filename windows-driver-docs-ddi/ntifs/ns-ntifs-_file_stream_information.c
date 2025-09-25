typedef struct _FILE_STREAM_INFORMATION {
  ULONG         NextEntryOffset;
  ULONG         StreamNameLength;
  LARGE_INTEGER StreamSize;
  LARGE_INTEGER StreamAllocationSize;
  WCHAR         StreamName[1];
} FILE_STREAM_INFORMATION, *PFILE_STREAM_INFORMATION;