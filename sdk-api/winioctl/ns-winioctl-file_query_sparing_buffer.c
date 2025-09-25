typedef struct _FILE_QUERY_SPARING_BUFFER {
  DWORD   SparingUnitBytes;
  BOOLEAN SoftwareSparing;
  DWORD   TotalSpareBlocks;
  DWORD   FreeSpareBlocks;
} FILE_QUERY_SPARING_BUFFER, *PFILE_QUERY_SPARING_BUFFER;