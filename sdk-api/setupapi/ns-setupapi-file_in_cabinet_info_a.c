typedef struct _FILE_IN_CABINET_INFO_A {
  PCSTR NameInCabinet;
  DWORD FileSize;
  DWORD Win32Error;
  WORD  DosDate;
  WORD  DosTime;
  WORD  DosAttribs;
  CHAR  FullTargetName[MAX_PATH];
} FILE_IN_CABINET_INFO_A, *PFILE_IN_CABINET_INFO_A;