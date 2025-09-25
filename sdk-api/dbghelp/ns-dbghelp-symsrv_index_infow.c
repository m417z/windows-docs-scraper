typedef struct {
  DWORD sizeofstruct;
  WCHAR file[MAX_PATH + 1];
  BOOL  stripped;
  DWORD timestamp;
  DWORD size;
  WCHAR dbgfile[MAX_PATH + 1];
  WCHAR pdbfile[MAX_PATH + 1];
  GUID  guid;
  DWORD sig;
  DWORD age;
} SYMSRV_INDEX_INFOW, *PSYMSRV_INDEX_INFOW;