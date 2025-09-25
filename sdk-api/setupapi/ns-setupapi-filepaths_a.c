typedef struct _FILEPATHS_A {
  PCSTR Target;
  PCSTR Source;
  UINT  Win32Error;
  DWORD Flags;
} FILEPATHS_A, *PFILEPATHS_A;