typedef struct {
  DWORD sizeofstruct;
  char  file[MAX_PATH + 1];
  BOOL  stripped;
  DWORD timestamp;
  DWORD size;
  char  dbgfile[MAX_PATH + 1];
  char  pdbfile[MAX_PATH + 1];
  GUID  guid;
  DWORD sig;
  DWORD age;
} SYMSRV_INDEX_INFO, *PSYMSRV_INDEX_INFO;