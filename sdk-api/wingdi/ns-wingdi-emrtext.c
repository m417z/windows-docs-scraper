typedef struct tagEMRTEXT {
  POINTL ptlReference;
  DWORD  nChars;
  DWORD  offString;
  DWORD  fOptions;
  RECTL  rcl;
  DWORD  offDx;
} EMRTEXT, *PEMRTEXT;