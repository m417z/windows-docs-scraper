typedef struct _FILE_STANDARD_INFO {
  LARGE_INTEGER AllocationSize;
  LARGE_INTEGER EndOfFile;
  DWORD         NumberOfLinks;
  BOOLEAN       DeletePending;
  BOOLEAN       Directory;
} FILE_STANDARD_INFO, *PFILE_STANDARD_INFO;