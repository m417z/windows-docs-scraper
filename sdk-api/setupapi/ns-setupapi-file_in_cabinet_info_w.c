typedef struct _FILE_IN_CABINET_INFO_W {
  PCWSTR NameInCabinet;
  DWORD  FileSize;
  DWORD  Win32Error;
  WORD   DosDate;
  WORD   DosTime;
  WORD   DosAttribs;
  WCHAR  FullTargetName[MAX_PATH];
} FILE_IN_CABINET_INFO_W, *PFILE_IN_CABINET_INFO_W;