typedef struct _FILEPATHS_W {
  PCWSTR Target;
  PCWSTR Source;
  UINT   Win32Error;
  DWORD  Flags;
} FILEPATHS_W, *PFILEPATHS_W;