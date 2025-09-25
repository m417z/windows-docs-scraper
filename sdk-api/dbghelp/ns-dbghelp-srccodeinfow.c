typedef struct _SRCCODEINFOW {
  DWORD   SizeOfStruct;
  PVOID   Key;
  DWORD64 ModBase;
  WCHAR   Obj[MAX_PATH + 1];
  WCHAR   FileName[MAX_PATH + 1];
  DWORD   LineNumber;
  DWORD64 Address;
} SRCCODEINFOW, *PSRCCODEINFOW;