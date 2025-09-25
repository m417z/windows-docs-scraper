typedef struct _SRCCODEINFO {
  DWORD   SizeOfStruct;
  PVOID   Key;
  DWORD64 ModBase;
  CHAR    Obj[MAX_PATH + 1];
  CHAR    FileName[MAX_PATH + 1];
  DWORD   LineNumber;
  DWORD64 Address;
} SRCCODEINFO, *PSRCCODEINFO;