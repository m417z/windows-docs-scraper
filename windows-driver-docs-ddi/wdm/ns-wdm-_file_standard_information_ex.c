typedef struct _FILE_STANDARD_INFORMATION_EX {
  LARGE_INTEGER AllocationSize;
  LARGE_INTEGER EndOfFile;
  ULONG         NumberOfLinks;
  BOOLEAN       DeletePending;
  BOOLEAN       Directory;
  BOOLEAN       AlternateStream;
  BOOLEAN       MetadataAttribute;
} FILE_STANDARD_INFORMATION_EX, *PFILE_STANDARD_INFORMATION_EX;